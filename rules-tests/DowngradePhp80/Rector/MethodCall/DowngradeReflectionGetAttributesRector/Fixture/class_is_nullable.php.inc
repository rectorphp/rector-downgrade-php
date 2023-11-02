<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeReflectionGetAttributesRector\Fixture;

class SomeClass
{
    public function run(?\ReflectionClass $reflectionClass)
    {
        if ($reflectionClass->getAttributes('SomeAttribute')[0] ?? null) {
            return true;
        }

        return false;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeReflectionGetAttributesRector\Fixture;

class SomeClass
{
    public function run(?\ReflectionClass $reflectionClass)
    {
        if ((method_exists($reflectionClass, 'getAttributes') ? $reflectionClass->getAttributes('SomeAttribute') : [])[0] ?? null) {
            return true;
        }

        return false;
    }
}

?>
