<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\BinaryOp\Equal;
use PhpParser\Node\Expr\BinaryOp\Identical;
use PhpParser\Node\Expr\BooleanNot;
use PhpParser\Node\Expr\Cast;
use PhpParser\Node\Expr\Cast\String_;
use PhpParser\Node\Expr\Empty_;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Ternary;
use Rector\PhpParser\Node\Value\ValueResolver;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://php.watch/versions/8.0/substr-out-of-bounds
 *
 * @see \Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\DowngradeSubstrFalsyRectorTest
 */
final class DowngradeSubstrFalsyRector extends AbstractRector
{
    /**
     * @var string
     */
    private const IS_UNCASTABLE = 'is_uncastable';

    public function __construct(
        private readonly ValueResolver $valueResolver
    ) {

    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Downgrade substr() with cast string on possibly falsy result', [
            new CodeSample('substr("a", 2);', '(string) substr("a", 2);'),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [Cast::class, Empty_::class, BooleanNot::class, Ternary::class, Equal::class, Identical::class, FuncCall::class];
    }

    /**
     * @param Cast|Empty_|BooleanNot|Ternary|Equal|Identical|FuncCall $node
     */
    public function refactor(Node $node): ?Node
    {
        if ($node instanceof Cast || $node instanceof Empty_ || $node instanceof BooleanNot) {
            $node->expr->setAttribute(self::IS_UNCASTABLE, true);
            return null;
        }

        if ($node instanceof Ternary) {
            if (! $node->if instanceof Expr) {
                $node->cond->setAttribute(self::IS_UNCASTABLE, true);
            }

            return null;
        }

        if ($node instanceof Equal || $node instanceof Identical) {
            if ($this->valueResolver->isFalse($node->left)) {
                $node->right->setAttribute(self::IS_UNCASTABLE, true);
            }

            if ($this->valueResolver->isFalse($node->right)) {
                $node->left->setAttribute(self::IS_UNCASTABLE, true);
            }

            return null;
        }

        if (! $this->isName($node, 'substr')) {
            return null;
        }

        if ($node->getAttribute(self::IS_UNCASTABLE) === true) {
            return null;
        }

        $type = $this->getType($node);
        if ($type->isNonEmptyString()->yes()) {
            return null;
        }

        return new String_($node);
    }
}
