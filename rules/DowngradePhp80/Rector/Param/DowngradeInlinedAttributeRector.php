<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\Param;

use PhpParser\Node;
use PhpParser\Node\Param;
use Rector\Core\Rector\AbstractRector;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://php.watch/articles/php-attributes#syntax
 *
 * @see \Rector\Tests\DowngradePhp80\Rector\Param\DowngradeInlinedAttributeRector\DowngradeInlinedAttributeRectorTest
 */
final class DowngradeInlinedAttributeRector extends AbstractRector
{
    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Refactor Inlined attribute markers to multiline so it marked as comment', [
            new CodeSample(
                <<<'CODE_SAMPLE'
function grep(#[\JetBrains\PhpStorm\Language('RegExp')] string $pattern)
{}
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
function grep(#[\JetBrains\PhpStorm\Language('RegExp')]
string $pattern)
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [Param::class];
    }

    /**
     * @param Param  $node
     */
    public function refactor(Node $node): ?Node
    {
        $attributeGroups = $node->attrGroups;

        if ($attributeGroups === []) {
            return null;
        }

        $currentAttrGroups = current($attributeGroups);
        $currentAttr = current($currentAttrGroups->attrs);

        dump($currentAttr->getLine());
        dump($node->getLine());

        if ($currentAttr->getLine() === $node->getLine()) {
            $node->setAttribute(AttributeKey::ORIGINAL_NODE, null);
            return $node;
        }

        print_node($node);
        return null;
    }
}
