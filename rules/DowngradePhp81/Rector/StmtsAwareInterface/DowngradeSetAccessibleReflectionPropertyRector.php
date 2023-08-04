<?php

declare(strict_types=1);

namespace Rector\DowngradePhp81\Rector\StmtsAwareInterface;

use PhpParser\Node;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://phpbackend.com/blog/post/php-8-1-accessing-private-protected-properties-methods-via-reflection-api-is-now-allowed-without-calling-setAccessible
 *
 * @see \Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\DowngradeSetAccessibleReflectionPropertyRectorTest
 */
final class DowngradeSetAccessibleReflectionPropertyRector extends AbstractRector
{
    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Add setAccessible() on ReflectionProperty to allow reading private properties in PHP 8.0-', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run($object)
    {
        $reflectionProperty = new ReflectionProperty(Foo::class, 'bar');

        return $reflectionProperty->getValue($object);
    }
}
CODE_SAMPLE

                ,
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run($object)
    {
        $reflectionProperty = new ReflectionProperty(Foo::class, 'bar');
        $reflectionProperty->setAccessible(true);

        return $reflectionProperty->getValue($object);
    }
}
CODE_SAMPLE

            )
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [\Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface::class];
    }

    /**
     * @param \Rector\Core\Contract\PhpParser\Node\StmtsAwareInterface $node
     */
    public function refactor(Node $node): ?Node
    {
        // change the node

        return $node;
    }
}
