<?php

namespace Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Source\GearValue;

final class ParamNullableMethod
{
    public function changeNullableGear(?GearValue $gearValue)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Source\GearValue;

final class ParamNullableMethod
{
    /**
     * @param ?\Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Source\GearValue::* $gearValue
     */
    public function changeNullableGear(?string $gearValue)
    {
    }
}

?>
