<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class SomeClass
{
    public function run($object)
    {
        $reflectionProperty = new ReflectionProperty(Foo::class, 'bar');

        return $reflectionProperty->getValue($object);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class SomeClass
{
    public function run($object)
    {
        $reflectionProperty = new ReflectionProperty(Foo::class, 'bar');
        $reflectionProperty->setAccessible(true);

        return $reflectionProperty->getValue($object);
    }
}

?>
