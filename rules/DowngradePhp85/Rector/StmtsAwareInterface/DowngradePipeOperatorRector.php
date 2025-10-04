<?php

declare(strict_types=1);

namespace Rector\DowngradePhp85\Rector\StmtsAwareInterface;

use PhpParser\Node;
use PhpParser\Node\Expr\BinaryOp\Pipe;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Expr\ArrowFunction;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\Return_;
use PhpParser\NodeTraverser;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;

/**
 * @see https://wiki.php.net/rfc/pipe-operator-v3
 * @see \Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\DowngradePipeOperatorRectorTest
 */
final class DowngradePipeOperatorRector extends AbstractRector
{
    /**
     * @var int
     */
    private $tempVariableCounter = 0;

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Downgrade pipe operator |> to PHP < 8.1 compatible code',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
$value = "hello world";
$result = $value
    |> function3(...)
    |> function2(...)
    |> function1(...);
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
$value = "hello world";
$result1 = function3($value);
$result2 = function2($result1);
$result = function1($result2);
CODE_SAMPLE
                ),
                new CodeSample(
                    <<<'CODE_SAMPLE'
$result = strtoupper("Hello World") |> trim(...);
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
$result = trim(strtoupper("Hello World"));
CODE_SAMPLE
                ),
            ]
        );
    }

    public function getNodeTypes(): array
    {
        return [Pipe::class];
    }

    public function refactor(Node $node): ?Node
    {
        if (!$node instanceof Pipe) {
            return null;
        }

        return $this->processPipeOperation($node);
    }

    private function processPipeOperation(Pipe $pipe): void
    {
       
    }

   
}