<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class SomeCollection
{
    public function getProperties(): array
    {
        return [];
    }
}

class SkipNonReflectionGetProperties
{
    public function run()
    {
        $collection = new SomeCollection();
        foreach ($collection->getProperties() as $property) {
            echo $property;
        }
    }
}
