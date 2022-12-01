<?php

namespace Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Fixture;

enum KeepOtherMethod
{
    case LEFT;

    case RIGHT;

    public static function otherMethod()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\Fixture;

class KeepOtherMethod
{
    public const LEFT = 'left';
    public const RIGHT = 'right';
    public static function otherMethod()
    {
    }
}

?>
