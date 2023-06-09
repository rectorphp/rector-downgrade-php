<?php

declare(strict_types=1);

namespace Rector\NodeAnalyzer;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Stmt;
use PhpParser\Node\Stmt\Do_;
use PhpParser\Node\Stmt\For_;
use PhpParser\Node\Stmt\Foreach_;
use PhpParser\Node\Stmt\If_;
use PhpParser\Node\Stmt\Switch_;
use PhpParser\Node\Stmt\While_;
use Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface;
use Rector\Core\PhpParser\Node\BetterNodeFinder;
use Rector\Core\Util\MultiInstanceofChecker;
use Rector\ValueObject\StmtAndExpr;

/**
 * To resolve Stmt and Expr in top StmtsAwareInterface from early Expr attribute
 * so the usage can append code before the Stmt
 */
final class TopStmtAndExprMatcher
{
    public function __construct(
        private readonly BetterNodeFinder $betterNodeFinder,
        private readonly MultiInstanceofChecker $multiInstanceofChecker
    ) {
    }

    /**
     * @param callable(Node $node): bool $filter
     */
    public function match(StmtsAwareInterface|Switch_ $stmtsAware, callable $filter): null|StmtAndExpr
    {
        if ($stmtsAware instanceof Closure) {
            return null;
        }

        $nodes = [];
        if ($stmtsAware instanceof Foreach_) {
            $nodes = [$stmtsAware->expr, $stmtsAware->keyVar, $stmtsAware->valueVar];
        }

        if ($stmtsAware instanceof For_) {
            $nodes = [$stmtsAware->init, $stmtsAware->cond, $stmtsAware->loop];
        }

        if ($this->multiInstanceofChecker->isInstanceOf($stmtsAware, [
            If_::class,
            While_::class,
            Do_::class,
            Switch_::class,
        ])) {
            /** @var If_|While_|Do_|Switch_ $stmtsAware */
            $nodes = [$stmtsAware->cond];
        }

        foreach ($nodes as $node) {
            // For top level Expr can be array of Expr in each property
            if (! $node instanceof Node && ! is_array($node)) {
                continue;
            }

            $expr = $this->betterNodeFinder->findFirst($node, $filter);
            if ($expr instanceof Expr) {
                return new StmtAndExpr($stmtsAware, $expr);
            }
        }

        $stmtAndExprFromChildCond = $this->resolveFromChildCond($stmtsAware, $filter);
        if ($stmtAndExprFromChildCond instanceof StmtAndExpr) {
            return $stmtAndExprFromChildCond;
        }

        return null;
    }

    /**
     * @param callable(Node $node): bool $filter
     */
    private function resolveFromChildCond(StmtsAwareInterface|Switch_ $stmtsAware, callable $filter): null|StmtAndExpr
    {
        if (! $stmtsAware instanceof If_ && ! $stmtsAware instanceof Switch_) {
            return null;
        }

        $stmts = $stmtsAware instanceof If_
            ? $stmtsAware->elseifs
            : $stmtsAware->cases;

        foreach ($stmts as $stmt) {
            if (! $stmt->cond instanceof Expr) {
                continue;
            }

            $expr = $this->betterNodeFinder->findFirst($stmt->cond, $filter);
            if ($expr instanceof Expr) {
                return new StmtAndExpr($stmtsAware, $expr);
            }
        }

        return null;
    }
}
