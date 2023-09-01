<?php

namespace Rector\Tests\DowngradePhp81\Rector\MethodCall\DowngradeIsEnumRector\Fixture;

class SomeClass
{
    public function run(\ReflectionClass $reflectionClass)
    {
        return $reflectionClass->isEnum();
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\MethodCall\DowngradeIsEnumRector\Fixture;

class SomeClass
{
    public function run(\ReflectionClass $reflectionClass)
    {
        return false;
    }
}

?>
