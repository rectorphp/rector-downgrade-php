<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\Cast\String_;
use PhpParser\Node\Expr\Empty_;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Ternary;
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
        return [String_::class, Empty_::class, Ternary::class, FuncCall::class];
    }

    /**
     * @param String_|Empty_|Ternary|FuncCall $node
     */
    public function refactor(Node $node): ?Node
    {
        if ($node instanceof String_ || $node instanceof Empty_) {
            $node->expr->setAttribute(self::IS_UNCASTABLE, true);
            return null;
        }

        if ($node instanceof Ternary) {
            if (! $node->if instanceof Expr) {
                $node->cond->setAttribute(self::IS_UNCASTABLE, true);
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
