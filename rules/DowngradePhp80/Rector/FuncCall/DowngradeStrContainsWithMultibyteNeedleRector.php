<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Arg;
use PhpParser\Node\Expr\BinaryOp\Identical;
use PhpParser\Node\Expr\BinaryOp\NotIdentical;
use PhpParser\Node\Expr\BooleanNot;
use PhpParser\Node\Scalar\String_;
use PhpParser\Node\Expr\FuncCall;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/str_contains
 *
 * @see \Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\DowngradeStrContainsWithMultibyteNeedleRectorTest
 */
final class DowngradeStrContainsWithMultibyteNeedleRector extends AbstractRector
{
    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Replace str_contains() with mb_strpos() !== false',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        return str_contains('😊abc', '😊a');
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        return mb_strpos('😊abc', '😊a') !== false;
    }
}
CODE_SAMPLE
                ),
            ]
        );
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [FuncCall::class, BooleanNot::class];
    }

    /**
     * @param FuncCall|BooleanNot $node
     * @return Identical|NotIdentical|null The refactored node.
     */
    public function refactor(Node $node): Identical | NotIdentical | null
    {
        $funcCall = $this->matchStrContainsOrNotStrContains($node);

        if (! $funcCall instanceof FuncCall) {
            return null;
        }

        if ($funcCall->isFirstClassCallable()) {
            return null;
        }

        $args = $funcCall->getArgs();
        if (count($args) < 2) {
            return null;
        }

        $haystack = $args[0]->value;
        $needle = $args[1]->value;
        $offset = null;

        if ($haystack instanceof FuncCall) {

            if (! $this->isName($haystack->name, 'mb_substr')) {
                return null;
            }

            if ($haystack->isFirstClassCallable()) {
                return null;
            }

            $substrArg = $haystack->getArgs();
            if (isset($substrArg[0]) && ! $substrArg[0] instanceof Arg) {
                return null;
            }

            if (isset($substrArg[1]) && ! $substrArg[1] instanceof Arg) {
                return null;
            }

            $haystack = $substrArg[0];
            $offset = $substrArg[1];
        }

        if (!$needle instanceof String_) {
            return null;
        }

        if(strlen($needle->value) === mb_strlen($needle->value)){
            return null;
        }
           
        if ($offset instanceof Arg) {
            $funcCall = $this->nodeFactory->createFuncCall('mb_strpos', [$haystack, $needle, $offset]);
        }

        if (! $offset instanceof Arg) {
            $funcCall = $this->nodeFactory->createFuncCall('mb_strpos', [$haystack, $needle]);
        }

        if ($node instanceof BooleanNot) {
            return new Identical($funcCall, $this->nodeFactory->createFalse());
        }

        return new NotIdentical($funcCall, $this->nodeFactory->createFalse());
    }

    private function matchStrContainsOrNotStrContains(FuncCall | BooleanNot $expr): ?FuncCall
    {
        $expr = ($expr instanceof BooleanNot) ? $expr->expr : $expr;
        if (! $expr instanceof FuncCall) {
            return null;
        }

        if (! $this->isName($expr, 'str_contains')) {
            return null;
        }

        return $expr;
    }
}
