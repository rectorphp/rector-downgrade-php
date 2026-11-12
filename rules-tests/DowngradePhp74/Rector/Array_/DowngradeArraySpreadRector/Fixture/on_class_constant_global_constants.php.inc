<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ClassWithGlobalConstants;

final class OnClassConstantGlobalConstants
{
    private const ITEMS = ['x', ...ClassWithGlobalConstants::ITEMS];
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ClassWithGlobalConstants;

final class OnClassConstantGlobalConstants
{
    private const ITEMS = ['x', PHP_EOL, \PHP_VERSION, T_STRING, true, null, UNKNOWN_CONSTANT];
}

?>
