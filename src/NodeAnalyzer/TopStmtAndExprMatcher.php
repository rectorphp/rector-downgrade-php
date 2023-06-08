<?php

declare(strict_types=1);

namespace Rector\NodeAnalyzer;

use PhpParser\Node;
use PhpParser\Node\Expr;
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
     * @return null|array<Stmt, Expr>
     */
    public function match(StmtsAwareInterface $stmtsAware, callable $filter): null|array
    {
        if ($stmtsAware instanceof Foreach_) {
            $nodes = array_filter([$stmtsAware->expr, $stmtsAware->keyVar, $stmtsAware->valueVar]);
        }

        if ($stmtsAware instanceof For_) {
            $nodes = array_filter([$stmtsAware->init, $stmtsAware->cond, $stmtsAware->loop]);
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
            $expr = $this->betterNodeFinder->findFirst($node, $filter);
            if ($expr instanceof Expr) {
                return [$stmtsAware, $expr];
            }
        }

        return null;
    }
}
