<?php

declare(strict_types=1);

namespace Rector\NodeAnalyzer;

use PhpParser\Node\Expr;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Scalar\String_;
use Rector\NodeNameResolver\NodeNameResolver;

final readonly class DefineFuncCallAnalyzer
{
    public function __construct(
        private NodeNameResolver $nodeNameResolver,
    ) {
    }

    /**
     * @param string[] $constants
     */
    public function isDefinedWithConstants(Expr $expr, array $constants): bool
    {
        if (! $expr instanceof FuncCall) {
            return false;
        }

        if (! $this->nodeNameResolver->isName($expr, 'defined')) {
            return false;
        }

        if ($expr->isFirstClassCallable()) {
            return false;
        }

        $firstArg = $expr->getArgs()[0];
        if (! $firstArg->value instanceof String_) {
            return false;
        }

        $string = $firstArg->value;
        return in_array($string->value, $constants, true);
    }
}
