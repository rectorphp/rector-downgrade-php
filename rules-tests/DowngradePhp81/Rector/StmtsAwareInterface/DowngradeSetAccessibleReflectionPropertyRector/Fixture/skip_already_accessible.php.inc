<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

final class SkipAlreadyAccessible
{
    public function run($object)
    {
        $reflectionProperty = new \ReflectionProperty($object, 'bar');
        $reflectionProperty->setAccessible(true);

        return $reflectionProperty->getValue($object);
    }
}
