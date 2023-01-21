<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

#[\Attribute]
final class KeepWillChangeAndAttribute
{
    #[\ReturnTypeWillChange]
    public function getValue()
    {
    }
}
