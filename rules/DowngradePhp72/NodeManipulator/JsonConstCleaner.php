<?php

declare(strict_types=1);

namespace Rector\DowngradePhp72\NodeManipulator;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\BinaryOp\BitwiseOr;
use PhpParser\Node\Expr\ConstFetch;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Scalar\LNumber;
use PhpParser\Node\Scalar\String_;
use Rector\Core\PhpParser\Node\BetterNodeFinder;
use Rector\Enum\JsonConstant;
use Rector\NodeNameResolver\NodeNameResolver;
use Rector\NodeTypeResolver\Node\AttributeKey;

final class JsonConstCleaner
{
    public function __construct(
        private readonly NodeNameResolver $nodeNameResolver,
        private readonly BetterNodeFinder $betterNodeFinder
    ) {
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    public function clean(ConstFetch|BitwiseOr $node, array $constants): ConstFetch|Expr|null
    {
        if ($node instanceof ConstFetch) {
            return $this->cleanByConstFetch($node, $constants);
        }

        return $this->cleanByBitwiseOr($node, $constants);
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    private function hasDefinedCheck(ConstFetch|BitwiseOr $node, array $constants): bool
    {
        return (bool) $this->betterNodeFinder->findFirstPrevious(
            $node,
            function (Node $subNode) use ($constants): bool {
                if (! $subNode instanceof FuncCall) {
                    return false;
                }

                if (! $this->nodeNameResolver->isName($subNode, 'defined')) {
                    return false;
                }

                $args = $subNode->getArgs();
                if (! isset($args[0])) {
                    return false;
                }

                if (! $args[0]->value instanceof String_) {
                    return false;
                }

                return in_array($args[0]->value->value, $constants, true);
            }
        );
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    private function cleanByConstFetch(ConstFetch $constFetch, array $constants): ?LNumber
    {
        if (! $this->nodeNameResolver->isNames($constFetch, $constants)) {
            return null;
        }

        $parentNode = $constFetch->getAttribute(AttributeKey::PARENT_NODE);
        if ($parentNode instanceof BitwiseOr) {
            return null;
        }

        if ($this->hasDefinedCheck($constFetch, $constants)) {
            return null;
        }

        return new LNumber(0);
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    private function cleanByBitwiseOr(BitwiseOr $bitwiseOr, array $constants): null|Expr|LNumber
    {
        $isLeftTransformed = $this->isTransformed($bitwiseOr->left, $constants);
        $isRightTransformed = $this->isTransformed($bitwiseOr->right, $constants);

        if (! $isLeftTransformed && ! $isRightTransformed) {
            return null;
        }

        if ($this->hasDefinedCheck($bitwiseOr, $constants)) {
            return null;
        }

        if (! $isLeftTransformed) {
            return $bitwiseOr->left;
        }

        if (! $isRightTransformed) {
            return $bitwiseOr->right;
        }

        return new LNumber(0);
    }

    /**
     * @param string[] $constants
     */
    private function isTransformed(Expr $expr, array $constants): bool
    {
        return $expr instanceof ConstFetch && $this->nodeNameResolver->isNames($expr, $constants);
    }
}
