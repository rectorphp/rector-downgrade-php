<?php

namespace Rector\Tests\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector\Fixture;

final class SomeCustomReflection
{
    public function hasPrototype(): bool
    {
        return true;
    }
}

function runOnOther(SomeCustomReflection $someCustomReflection): bool
{
    return $someCustomReflection->hasPrototype();
}
