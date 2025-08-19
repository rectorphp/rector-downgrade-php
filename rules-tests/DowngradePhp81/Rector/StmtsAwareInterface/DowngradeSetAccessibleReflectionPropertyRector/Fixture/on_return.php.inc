<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnReturn
{
    public function run($object)
    {
        return new \ReflectionMethod($object, 'bar');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\StmtsAwareInterface\DowngradeSetAccessibleReflectionPropertyRector\Fixture;

class OnReturn
{
    public function run($object)
    {
        $reflection = new \ReflectionMethod($object, 'bar');
        if (PHP_VERSION_ID < 80100) {
            $reflection->setAccessible(true);
        }
        return $reflection;
    }
}

?>
