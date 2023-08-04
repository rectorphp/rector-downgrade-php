<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\NullsafeMethodCall;

use PhpParser\Node;
use PhpParser\Node\Expr\Assign;
use PhpParser\Node\Expr\MethodCall;
use PhpParser\Node\Expr\NullsafeMethodCall;
use PhpParser\Node\Expr\NullsafePropertyFetch;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Expr\Ternary;
use PhpParser\Node\Expr\Variable;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\DowngradeNullsafeToTernaryOperatorRectorTest
 */
final class DowngradeNullsafeToTernaryOperatorRector extends AbstractRector
{
    private int $counter = 1;

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Change nullsafe operator to ternary operator rector', [
            new CodeSample(
                <<<'CODE_SAMPLE'
$dateAsString = $booking->getStartDate()?->asDateTimeString();
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
$dateAsString = ($bookingGetStartDate = $booking->getStartDate()) ? $bookingGetStartDate->asDateTimeString() : null;
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [NullsafeMethodCall::class, NullsafePropertyFetch::class];
    }

    /**
     * @param NullsafeMethodCall|NullsafePropertyFetch $node
     */
    public function refactor(Node $node): Ternary
    {
        $variableName = $this->createNullsafeVariableName($node->var);
        $variable = new Variable($variableName);

        $methodCallOrPropertyFetch = $node instanceof NullsafeMethodCall
            ? new MethodCall($variable, $node->name, $node->getArgs())
            : new PropertyFetch($variable, $node->name);

        $assign = new Assign($variable, $node->var);
        return new Ternary($assign, $methodCallOrPropertyFetch, $this->nodeFactory->createNull());
    }

    private function createNullsafeVariableName(): string
    {
        return 'nullsafeVariable' . $this->counter++;
    }
}
