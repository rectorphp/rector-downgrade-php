<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

use ReflectionMethod;

function firstClassCallable(ReflectionMethod $reflectionMethod): callable
{
    return $reflectionMethod->hasPrototype(...);
}
