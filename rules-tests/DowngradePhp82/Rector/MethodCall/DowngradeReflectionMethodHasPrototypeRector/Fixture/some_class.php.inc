<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

use ReflectionMethod;

function checkPrototype(ReflectionMethod $reflectionMethod): bool
{
    return $reflectionMethod->hasPrototype();
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

use ReflectionMethod;

function checkPrototype(ReflectionMethod $reflectionMethod): bool
{
    return (function (\ReflectionMethod $reflectionMethod2): bool {
        try {
            $reflectionMethod2->getPrototype();
            return true;
        } catch (\ReflectionException) {
            return false;
        }
    })($reflectionMethod);
}

?>
