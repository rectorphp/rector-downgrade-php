<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnReflectionMethod
{
    public function run($object)
    {
        $reflectionMethod = new \ReflectionMethod($object, 'bar');
        return $reflectionMethod->__invoke($object, []);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnReflectionMethod
{
    public function run($object)
    {
        $reflectionMethod = new \ReflectionMethod($object, 'bar');
        $reflectionMethod->setAccessible(true);
        return $reflectionMethod->__invoke($object, []);
    }
}

?>
