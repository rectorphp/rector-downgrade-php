<?php

declare(strict_types=1);

namespace Rector\DowngradePhp83\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\CallLike;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Stmt\Echo_;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\Return_;
use PhpParser\Node\Stmt\Switch_;
use PHPStan\Analyser\Scope;
use Rector\Contract\PhpParser\Node\StmtsAwareInterface;
use Rector\Exception\ShouldNotHappenException;
use Rector\NodeAnalyzer\ExprInTopStmtMatcher;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Rector\PhpParser\Parser\InlineCodeParser;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/json_validate
 *
 * @see \Rector\Tests\DowngradePhp83\Rector\FuncCall\DowngradeJsonValidateRector\DowngradeJsonValidateRectorTest
 */
final class DowngradeJsonValidateRector extends AbstractRector
{
    private ?Closure $cachedClosure = null;

    public function __construct(
        private readonly InlineCodeParser $inlineCodeParser,
        private readonly ExprInTopStmtMatcher $exprInTopStmtMatcher
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Replace json_validate() function', [
            new CodeSample(
                <<<'CODE_SAMPLE'
json_validate('{"foo": "bar"}');
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
$jsonValidate = function (string $json, int $depth = 512, int $flags = 0) {
    if (function_exists('json_validate'))  {
        return json_validate($json, $depth, $flags);
    }

    $maxDepth = 0x7FFFFFFF;

    if (0 !== $flags && \defined('JSON_INVALID_UTF8_IGNORE') && \JSON_INVALID_UTF8_IGNORE !== $flags) {
        throw new \ValueError('json_validate(): Argument #3 ($flags) must be a valid flag (allowed flags: JSON_INVALID_UTF8_IGNORE)');
    }

    if ($depth <= 0) {
        throw new \ValueError('json_validate(): Argument #2 ($depth) must be greater than 0');
    }

    if ($depth > $maxDepth) {
        throw new \ValueError(sprintf('json_validate(): Argument #2 ($depth) must be less than %d', $maxDepth));
    }

    json_decode($json, true, $depth, $flags);
    return \JSON_ERROR_NONE === json_last_error();
};
$jsonValidate('{"foo": "bar"}');
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [StmtsAwareInterface::class, Switch_::class, Return_::class, Expression::class, Echo_::class];
    }

    /**
     * @param StmtsAwareInterface|Switch_|Return_|Expression|Echo_ $node
     * @return Node[]|null
     */
    public function refactor(Node $node): ?array
    {
        $expr = $this->exprInTopStmtMatcher->match(
            $node,
            function (Node $subNode): bool {
                if (! $subNode instanceof FuncCall) {
                    return false;
                }

                // need pull Scope from target traversed sub Node
                return ! $this->shouldSkip($subNode);
            }
        );

        if (! $expr instanceof FuncCall) {
            return null;
        }

        $variable = new Variable('jsonValidate');

        $function = $this->createClosure();
        $expression = new Expression(new Assign($variable, $function));

        $expr->name = $variable;

        return [$expression, $node];
    }

    private function createClosure(): Closure
    {
        if ($this->cachedClosure instanceof Closure) {
            return clone $this->cachedClosure;
        }

        $stmts = $this->inlineCodeParser->parseFile(__DIR__ . '/../../snippet/json_validate_closure.php.inc');

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

        if (! $this->isName($callLike, 'json_validate')) {
            return true;
        }

        $scope = $callLike->getAttribute(AttributeKey::SCOPE);
        if ($scope instanceof Scope && $scope->isInFunctionExists('json_validate')) {
            return true;
        }

        if ($callLike->isFirstClassCallable()) {
            return true;
        }

        $args = $callLike->getArgs();
        return count($args) < 1;
    }
}
