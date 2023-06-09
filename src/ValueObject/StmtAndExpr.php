<?php

declare(strict_types=1);

namespace Rector\ValueObject;

use PhpParser\Node\Expr;
use PhpParser\Node\Stmt\Switch_;
use Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface;

final class StmtAndExpr
{
    public function __construct(
        private readonly StmtsAwareInterface|Switch_ $stmt,
        private readonly Expr $expr,
    ) {
    }

    public function getStmt(): StmtsAwareInterface|Switch_
    {
        return $this->stmt;
    }

    public function getExpr(): Expr
    {
        return $this->expr;
    }
}
