<?php

declare(strict_types=1);

namespace Rector\NodeFactory;

use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Stmt;
use Rector\Naming\Naming\VariableNaming;
use Rector\NodeTypeResolver\Node\AttributeKey;

final class NamedVariableFactory
{
    public function __construct(
        private readonly VariableNaming $variableNaming,
    ) {
    }

    public function createVariable(string $variableName, Stmt $currentStmt): Variable
    {
        $scope = $currentStmt->getAttribute(AttributeKey::SCOPE);

        $variableName = $this->variableNaming->createCountedValueName($variableName, $scope);
        return new Variable($variableName);
    }
}
