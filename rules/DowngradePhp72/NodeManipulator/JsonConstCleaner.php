<?php

declare(strict_types=1);

namespace Rector\DowngradePhp72\NodeManipulator;

use PhpParser\Node\Expr;
use PhpParser\Node\Expr\BinaryOp\BitwiseOr;
use PhpParser\Node\Expr\ConstFetch;
use PhpParser\Node\Scalar\LNumber;
use Rector\NodeNameResolver\NodeNameResolver;

final class JsonConstCleaner
{
    /**
     * @var string
     */
    private const IS_CONSTFETCH_FROM_BITWISE_OR = 'is_constfetch_from_bitwise_or';

    public function __construct(
        private readonly NodeNameResolver $nodeNameResolver,
    ) {
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    public function clean(ConstFetch|BitwiseOr $node, array $constants): Expr|null
    {
        if ($node instanceof BitwiseOr) {
            if ($node->left instanceof ConstFetch) {
                $node->left->setAttribute(self::IS_CONSTFETCH_FROM_BITWISE_OR, true);
            }

            if ($node->right instanceof ConstFetch) {
                $node->right->setAttribute(self::IS_CONSTFETCH_FROM_BITWISE_OR, true);
            }
        }

        if ($node instanceof ConstFetch) {
            return $this->cleanByConstFetch($node, $constants);
        }

        return $this->cleanByBitwiseOr($node, $constants);
    }

    /**
     * @param array<JsonConstant::*> $constants
     */
    private function cleanByConstFetch(ConstFetch $constFetch, array $constants): ?LNumber
    {
        if (! $this->nodeNameResolver->isNames($constFetch, $constants)) {
            return null;
        }

        if ($constFetch->getAttribute(self::IS_CONSTFETCH_FROM_BITWISE_OR) === true) {
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
