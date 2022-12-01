<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\ClassMethod;

use PhpParser\Node;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://3v4l.org/Wgj19
 *
 * @see \Rector\Tests\DowngradePhp80\Rector\ClassMethod\RemoveReturnTypeDeclarationFromCloneRector\RemoveReturnTypeDeclarationFromCloneRectorTest
 */
final class RemoveReturnTypeDeclarationFromCloneRector extends AbstractRector
{
    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Remove return type from __clone() method', [
            new CodeSample(
                <<<'CODE_SAMPLE'
final class SomeClass
{
    public function __clone(): void
    {
    }
}
CODE_SAMPLE

                ,
                <<<'CODE_SAMPLE'
final class SomeClass
{
    public function __clone()
    {
    }
}
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [\PhpParser\Node\Stmt\ClassMethod::class];
    }

    /**
     * @param \PhpParser\Node\Stmt\ClassMethod $node
     */
    public function refactor(Node $node): ?Node
    {
        if (! $this->isName($node, '__clone')) {
            return null;
        }

        if (! $node->returnType instanceof \PhpParser\Node) {
            return null;
        }

        $node->returnType = null;

        return $node;
    }
}
