<?php

declare(strict_types=1);

namespace Rector\NodeAnalyzer;

use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Name;
use Rector\Core\PhpParser\Node\BetterNodeFinder;

final class StmtMatcher
{
    public function __construct(
        private readonly BetterNodeFinder $betterNodeFinder,
    ) {
    }

    /**
     * @param \PhpParser\Node|\PhpParser\Node[] $stmt
     */
    public function matchFuncCallNamed(\PhpParser\Node | array $stmt, string $functionName): ?FuncCall
    {
        /** @var FuncCall[] $funcCalls */
        $funcCalls = $this->betterNodeFinder->findInstancesOf($stmt, [FuncCall::class]);

        foreach ($funcCalls as $funcCall) {
            if (! $funcCall->name instanceof Name) {
                continue;
            }

            if ($funcCall->name->toString() !== $functionName) {
                continue;
            }

            return $funcCall;
        }

        return null;
    }
}
