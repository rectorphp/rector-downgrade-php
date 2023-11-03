<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeReflectionGetAttributesRector\Fixture;

class UseReflectionProperty
{
    public function run(\ReflectionProperty $reflectionProperty)
    {
        if ($reflectionProperty->getAttributes()) {
            return true;
        }

        return false;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeReflectionGetAttributesRector\Fixture;

class UseReflectionProperty
{
    public function run(\ReflectionProperty $reflectionProperty)
    {
        if (method_exists($reflectionProperty, 'getAttributes') ? $reflectionProperty->getAttributes() : []) {
            return true;
        }

        return false;
    }
}

?>
