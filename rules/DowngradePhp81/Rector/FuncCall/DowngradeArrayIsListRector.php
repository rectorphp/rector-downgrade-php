<?php

declare(strict_types=1);

namespace Rector\DowngradePhp81\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\CallLike;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Expr\ClosureUse;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Stmt;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\If_;
use PhpParser\Node\Stmt\Return_;
use PHPStan\Analyser\Scope;
use Rector\Core\Exception\ShouldNotHappenException;
use Rector\Core\PhpParser\Parser\InlineCodeParser;
use Rector\Core\Rector\AbstractScopeAwareRector;
use Rector\DowngradePhp72\NodeAnalyzer\FunctionExistsFunCallAnalyzer;
use Rector\Naming\Naming\VariableNaming;
use Rector\NodeAnalyzer\TopStmtAndExprMatcher;
use Rector\ValueObject\StmtAndExpr;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/is_list
 *
 * @see \Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeArrayIsListRector\DowngradeArrayIsListRectorTest
 */
final class DowngradeArrayIsListRector extends AbstractScopeAwareRector
{
    private ?Closure $cachedClosure = null;

    public function __construct(
        private readonly InlineCodeParser $inlineCodeParser,
        private readonly FunctionExistsFunCallAnalyzer $functionExistsFunCallAnalyzer,
        private readonly VariableNaming $variableNaming,
        private readonly TopStmtAndExprMatcher $topStmtAndExprMatcher
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Replace array_is_list() function', [
            new CodeSample(
                <<<'CODE_SAMPLE'
array_is_list([1 => 'apple', 'orange']);
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
$arrayIsList = function (array $array) : bool {
    if (function_exists('array_is_list')) {
        return array_is_list($array);
    }

    if ($array === []) {
        return true;
    }

    $current_key = 0;
    foreach ($array as $key => $noop) {
        if ($key !== $current_key) {
            return false;
        }
        ++$current_key;
    }

    return true;
};
$arrayIsList([1 => 'apple', 'orange']);
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return $this->topStmtAndExprMatcher->getStmts();
    }

    /**
     * @param Stmt $node
     * @return Stmt[]|null
     */
    public function refactorWithScope(Node $node, Scope $scope): ?array
    {
        $stmtAndExpr = $this->topStmtAndExprMatcher->match(
            $node,
            function (Node $subNode): bool {
                if (! $subNode instanceof FuncCall) {
                    return false;
                }

                return ! $this->shouldSkip($subNode);
            });

        if (! $stmtAndExpr instanceof StmtAndExpr) {
            return null;
        }

        $stmt = $stmtAndExpr->getStmt();
        /** @var FuncCall $funcCall */
        $funcCall = $stmtAndExpr->getExpr();
        $variable = new Variable($this->variableNaming->createCountedValueName('arrayIsList', $scope));

        $function = $this->createClosure();
        $expression = new Expression(new Assign($variable, $function));

        $funcCall->name = $variable;

        return [$expression, $stmt];
    }

    private function createClosure(): Closure
    {
        if ($this->cachedClosure instanceof Closure) {
            return clone $this->cachedClosure;
        }

        $stmts = $this->inlineCodeParser->parse(__DIR__ . '/../../snippet/array_is_list_closure.php.inc');

        /** @var Expression $expression */
        $expression = $stmts[0];

        $expr = $expression->expr;
        if (! $expr instanceof Closure) {
            throw new ShouldNotHappenException();
        }

        $this->cachedClosure = $expr;

        return $expr;
    }

    private function shouldSkip(CallLike $callLike): bool
    {
        if (! $callLike instanceof FuncCall) {
            return false;
        }

        if (! $this->nodeNameResolver->isName($callLike, 'array_is_list')) {
            return true;
        }

        if ($this->functionExistsFunCallAnalyzer->detect($callLike, 'array_is_list')) {
            return true;
        }

        $args = $callLike->getArgs();
        return count($args) !== 1;
    }
}
