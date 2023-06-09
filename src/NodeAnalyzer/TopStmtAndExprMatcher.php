<?php

declare(strict_types=1);

namespace Rector\NodeAnalyzer;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Stmt\Do_;
use PhpParser\Node\Stmt\Echo_;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\For_;
use PhpParser\Node\Stmt\Foreach_;
use PhpParser\Node\Stmt\If_;
use PhpParser\Node\Stmt\Return_;
use PhpParser\Node\Stmt\Switch_;
use PhpParser\Node\Stmt\While_;
use Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface;
use Rector\Core\PhpParser\Node\BetterNodeFinder;
use Rector\Core\Util\MultiInstanceofChecker;
use Rector\ValueObject\StmtAndExpr;

/**
 * To resolve Stmt and Expr in top stmtInterface from early Expr attribute
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
     * @return array<class-string<StmtsAwareInterface|Switch_|Return_|Expression|Echo_>>
     */
    public function getStmts(): array
    {
        return [StmtsAwareInterface::class, Switch_::class, Return_::class, Expression::class, Echo_::class];
    }

    /**
     * @param callable(Node $node): bool $filter
     */
    public function match(
        StmtsAwareInterface|Switch_|Return_|Expression|Echo_ $stmt,
        callable $filter
    ): null|StmtAndExpr {
        if ($stmt instanceof Closure) {
            return null;
        }

        $nodes = [];
        if ($stmt instanceof Foreach_) {
            $nodes = [$stmt->expr, $stmt->keyVar, $stmt->valueVar];
        }

        if ($stmt instanceof For_) {
            $nodes = [$stmt->init, $stmt->cond, $stmt->loop];
        }

        if ($this->multiInstanceofChecker->isInstanceOf($stmt, [
            If_::class,
            While_::class,
            Do_::class,
            Switch_::class,
        ])) {
            /** @var If_|While_|Do_|Switch_ $stmt */
            $nodes = [$stmt->cond];
        }

        foreach ($nodes as $node) {
            // For top level Expr can be array of Expr in each property
            if (! $node instanceof Node && ! is_array($node)) {
                continue;
            }

            $expr = $this->betterNodeFinder->findFirst($node, $filter);
            if ($expr instanceof Expr) {
                return new StmtAndExpr($stmt, $expr);
            }
        }

        $stmtAndExpr = $this->resolveFromChildCond($stmt, $filter);
        if ($stmtAndExpr instanceof StmtAndExpr) {
            return $stmtAndExpr;
        }

        if (($stmt instanceof Return_ || $stmt instanceof Expression) && $stmt->expr instanceof Expr) {
            $expr = $this->betterNodeFinder->findFirst($stmt->expr, $filter);
            if ($expr instanceof Expr) {
                return new StmtAndExpr($stmt, $expr);
            }
        }

        return null;
    }

    /**
     * @param callable(Node $node): bool $filter
     */
    private function resolveFromChildCond(
        StmtsAwareInterface|Switch_|Return_|Expression|Echo_ $stmt,
        callable $filter
    ): null|StmtAndExpr {
        if (! $stmt instanceof If_ && ! $stmt instanceof Switch_) {
            return null;
        }

        $stmts = $stmt instanceof If_
            ? $stmt->elseifs
            : $stmt->cases;

        foreach ($stmts as $stmt) {
            if (! $stmt->cond instanceof Expr) {
                continue;
            }

            $expr = $this->betterNodeFinder->findFirst($stmt->cond, $filter);
            if ($expr instanceof Expr) {
                return new StmtAndExpr($stmt, $expr);
            }
        }

        return null;
    }
}
