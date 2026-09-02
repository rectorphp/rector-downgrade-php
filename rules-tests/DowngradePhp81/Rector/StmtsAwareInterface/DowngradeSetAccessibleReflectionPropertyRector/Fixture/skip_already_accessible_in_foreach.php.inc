<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class SkipAlreadyAccessibleInForeach
{
    public function run($object)
    {
        $reflectionObject = new \ReflectionObject($object);
        foreach ($reflectionObject->getProperties() as $reflectionProperty) {
            if (PHP_VERSION_ID < 80100) {
                $reflectionProperty->setAccessible(true);
            }
            echo $reflectionProperty->getValue($object);
        }
    }
}
