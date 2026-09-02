<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnGetMethods
{
    public function run($object)
    {
        $reflectionClass = new \ReflectionClass($object);
        foreach ($reflectionClass->getMethods() as $reflectionMethod) {
            $reflectionMethod->invoke($object);
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnGetMethods
{
    public function run($object)
    {
        $reflectionClass = new \ReflectionClass($object);
        foreach ($reflectionClass->getMethods() as $reflectionMethod) {
            if (PHP_VERSION_ID < 80100) {
                $reflectionMethod->setAccessible(true);
            }
            $reflectionMethod->invoke($object);
        }
    }
}

?>
