<?php

declare(strict_types=1);

namespace Rector\DowngradePhp72\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Stmt\Echo_;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\Return_;
use PhpParser\Node\Stmt\Switch_;
use PHPStan\Analyser\Scope;
use Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface;
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
 * @changelog https://github.com/symfony/polyfill/commit/cc2bf55accd32b989348e2039e8c91cde46aebed
 *
 * @see \Rector\Tests\DowngradePhp72\Rector\FuncCall\DowngradeStreamIsattyRector\DowngradeStreamIsattyRectorTest
 */
final class DowngradeStreamIsattyRector extends AbstractScopeAwareRector
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
        return new RuleDefinition('Downgrade stream_isatty() function', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run($stream)
    {
        $isStream = stream_isatty($stream);
    }
}
CODE_SAMPLE

                ,
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run($stream)
    {
        $streamIsatty = function ($stream) {
            if (\function_exists('stream_isatty')) {
                return stream_isatty($stream);
            }

            if (!\is_resource($stream)) {
                trigger_error('stream_isatty() expects parameter 1 to be resource, '.\gettype($stream).' given', \E_USER_WARNING);

                return false;
            }

            if ('\\' === \DIRECTORY_SEPARATOR) {
                $stat = @fstat($stream);
                // Check if formatted mode is S_IFCHR
                return $stat ? 0020000 === ($stat['mode'] & 0170000) : false;
            }

            return \function_exists('posix_isatty') && @posix_isatty($stream);
        };
        $isStream = $streamIsatty($stream);
    }
}
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
    public function refactorWithScope(Node $node, Scope $scope): ?array
    {
        $stmtAndExpr = $this->topStmtAndExprMatcher->match(
            $node,
            function (Node $subNode): bool {
                if (! $subNode instanceof FuncCall) {
                    return false;
                }

                if (! $this->isName($subNode, 'stream_isatty')) {
                    return false;
                }

                return ! $this->functionExistsFunCallAnalyzer->detect($subNode, 'stream_isatty');
            }
        );

        if (! $stmtAndExpr instanceof StmtAndExpr) {
            return null;
        }

        $stmt = $stmtAndExpr->getStmt();
        /** @var FuncCall $expr */
        $expr = $stmtAndExpr->getExpr();

        $function = $this->createClosure();

        $variable = new Variable($this->variableNaming->createCountedValueName('streamIsatty', $scope));
        $assign = new Assign($variable, $function);

        $expr->name = $variable;

        return [new Expression($assign), $stmt];
    }

    private function createClosure(): Closure
    {
        if ($this->cachedClosure instanceof Closure) {
            return clone $this->cachedClosure;
        }

        $stmts = $this->inlineCodeParser->parse(__DIR__ . '/../../snippet/isatty_closure.php.inc');

        /** @var Expression $expression */
        $expression = $stmts[0];

        $expr = $expression->expr;
        if (! $expr instanceof Closure) {
            throw new ShouldNotHappenException();
        }

        $this->cachedClosure = $expr;

        return $expr;
    }
}
