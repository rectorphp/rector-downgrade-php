<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

final class SkipAlreadyIfPhpVersion
{
    public function run($object)
    {
        $reflectionProperty = new \ReflectionProperty($object, 'bar');
        if (PHP_VERSION_ID < 80100) {
            $reflectionProperty->setAccessible(true);
        }

        return $reflectionProperty->getValue($object);
    }
}
