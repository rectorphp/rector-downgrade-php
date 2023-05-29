<?php

declare(strict_types=1);

namespace Rector\DowngradePhp71\Rector\List_;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\Array_;
use PhpParser\Node\Expr\ArrayDimFetch;
use PhpParser\Node\Expr\ArrayItem;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\List_;
use PhpParser\Node\Expr\Variable;
use PhpParser\Node\Stmt;
use PhpParser\Node\Stmt\Expression;
use PhpParser\Node\Stmt\Foreach_;
use Rector\Core\Rector\AbstractRector;
use Rector\Naming\ExpectedNameResolver\InflectorSingularResolver;
use Rector\Naming\Naming\VariableNaming;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp71\Rector\List_\DowngradeKeysInListRector\DowngradeKeysInListRectorTest
 */
final class DowngradeKeysInListRector extends AbstractRector
{
    public function __construct(
        private readonly InflectorSingularResolver $inflectorSingularResolver,
        private readonly VariableNaming $variableNaming,
    ) {
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [Expression::class];
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Extract keys in list to its own variable assignment',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run(): void
    {
        $data = [
            ["id" => 1, "name" => 'Tom'],
            ["id" => 2, "name" => 'Fred'],
        ];

        list("id" => $id1, "name" => $name1) = $data[0];
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run(): void
    {
        $data = [
            ["id" => 1, "name" => 'Tom'],
            ["id" => 2, "name" => 'Fred'],
        ];

        $id1 = $data[0]["id"];
        $name1 = $data[0]["name"];
    }
}
CODE_SAMPLE
                ),
            ]
        );
    }

    /**
     * @param Expression $node
     */
    public function refactor(Node $node)
    {
        if ($node instanceof Expression) {
            if ($node->expr instanceof Assign) {
                return $this->refactorAssignExpression($node);
            }

            return null;
        }

        if ($node instanceof Foreach_) {
            if (! $node->expr instanceof Assign) {
                return null;
            }

            /** @var Assign $assign */
            $assign = $node->expr;
            if (! $assign->var instanceof List_ && ! $assign->var instanceof Array_) {
                return null;
            }

            $assignedArrayOrList = $assign->var;

            $defaultValueVar = $this->inflectorSingularResolver->resolve((string) $this->getName($assign->var));
            //            $scope = $parentNode->getAttribute(AttributeKey::SCOPE);

            $scope = $node->getAttributes(AttributeKey::SCOPE);
            $newValueVar = $this->variableNaming->createCountedValueName($defaultValueVar, $scope);
            $node->valueVar = new Variable($newValueVar);
            $stmts = $node->stmts;

            $assignExpressions = $this->processExtractToItsOwnVariable($assignedArrayOrList, $assign, $expression);

            if ($stmts === []) {
                $node->stmts = $assignExpressions;
            } else {
                return [...$assignExpressions, $node->stmts[0]];
            }

            return $node->valueVar;
        }

        return null;
    }

    /**
     * @return Stmt[]
     */
    private function processExtractToItsOwnVariable(
        List_ | Array_ $node,
        Assign $assign,
        Expression|Foreach_ $expressionOrForeach
    ): array {
        $items = $node->items;

        $assignStmts = [];

        foreach ($items as $item) {
            if (! $item instanceof ArrayItem) {
                return [];
            }

            // keyed and not keyed cannot be mixed, return early
            if (! $item->key instanceof Expr) {
                return [];
            }

            if ($expressionOrForeach instanceof Expression && $assign instanceof Assign && $assign->var === $node) {
                $assignStmts[] = new Expression(
                    new Assign($item->value, new ArrayDimFetch($assign->expr, $item->key))
                );
            }

            if (! $assign instanceof Foreach_) {
                continue;
            }

            if ($assign->valueVar !== $node) {
                continue;
            }

            $assignStmts[] = $this->getExpressionFromForeachValue($assign, $item);
        }

        return $assignStmts;
    }

    private function getExpressionFromForeachValue(Foreach_ $foreach, ArrayItem $arrayItem): Expression
    {
        $defaultValueVar = $this->inflectorSingularResolver->resolve((string) $this->getName($foreach->expr));

        $scope = $foreach->getAttribute(AttributeKey::SCOPE);

        $newValueVar = $this->variableNaming->createCountedValueName($defaultValueVar, $scope);
        $assign = new Assign($arrayItem->value, new ArrayDimFetch(new Variable($newValueVar), $arrayItem->key));

        return new Expression($assign);
    }

    /**
     * @param Expression<Assign> $expression
     * @return Stmt[]|null
     */
    private function refactorAssignExpression(Expression $expression): ?array
    {
        /** @var Assign $assign */
        $assign = $expression->expr;
        if (! $assign->var instanceof List_ && ! $assign->var instanceof Array_) {
            return null;
        }

        $assignedArrayOrList = $assign->var;

        $assignExpressions = $this->processExtractToItsOwnVariable($assignedArrayOrList, $assign, $expression);
        if ($assignExpressions === []) {
            return null;
        }

        $this->mirrorComments($assignExpressions[0], $expression);

        return [$assignExpressions, $expression];
    }
}
