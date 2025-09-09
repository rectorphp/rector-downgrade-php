<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

#[\Attribute]final class AttributeSameLine
{
    #[\ReturnTypeWillChange]
    public function getValue()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

#[\Attribute]
final class AttributeSameLine
{
    #[\ReturnTypeWillChange]
    public function getValue()
    {
    }
}

?>
