<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

use ReflectionMethod;

function resolvePrototype(ReflectionMethod $reflectionMethod): ReflectionMethod
{
    if ($reflectionMethod->hasPrototype()) {
        $reflectionMethod = $reflectionMethod->getPrototype();
    }

    return $reflectionMethod;
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

use ReflectionMethod;

function resolvePrototype(ReflectionMethod $reflectionMethod): ReflectionMethod
{
    if ((function (\ReflectionMethod $reflectionMethod): bool {
        try {
            $reflectionMethod->getPrototype();
            return true;
        } catch (\ReflectionException) {
            return false;
        }
    })($reflectionMethod)) {
        $reflectionMethod = $reflectionMethod->getPrototype();
    }

    return $reflectionMethod;
}

?>
