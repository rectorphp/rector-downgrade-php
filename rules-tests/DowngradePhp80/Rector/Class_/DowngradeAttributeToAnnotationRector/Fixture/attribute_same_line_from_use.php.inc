<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use Attribute;
use ReturnTypeWillChange;

#[Attribute]final class AttributeSameLineFromUse
{
    #[ReturnTypeWillChange]public function getValue()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use Attribute;
use ReturnTypeWillChange;

#[Attribute]
final class AttributeSameLineFromUse
{
    #[ReturnTypeWillChange]
    public function getValue()
    {
    }
}

?>
