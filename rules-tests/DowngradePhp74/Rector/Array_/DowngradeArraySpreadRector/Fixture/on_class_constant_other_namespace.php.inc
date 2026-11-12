<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ClassWithArrayConstant;

final class OnClassConstantOtherNamespace extends ClassWithArrayConstant
{
    private const FROM_OTHER = ['x', ...ClassWithArrayConstant::ITEMS];

    private const FROM_INHERITED = ['y', ...OnClassConstantOtherNamespace::ITEMS];
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ClassWithArrayConstant;

final class OnClassConstantOtherNamespace extends ClassWithArrayConstant
{
    private const FROM_OTHER = ['x', 'a', \Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\SomeTokens::TOKEN];

    private const FROM_INHERITED = ['y', 'a', \Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\SomeTokens::TOKEN];
}

?>
