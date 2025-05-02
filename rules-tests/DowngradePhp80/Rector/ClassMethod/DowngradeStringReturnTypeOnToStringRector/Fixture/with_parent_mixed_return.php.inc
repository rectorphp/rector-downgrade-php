<?php

namespace Rector\Tests\DowngradePhp80\Rector\ClassMethod\DowngradeStringReturnTypeOnToStringRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\ClassMethod\DowngradeStringReturnTypeOnToStringRector\Source\ParentClassWithToStringMixedReturn;

// @see https://3v4l.org/IrE2q#v7.4.33
class WithParentMixedReturn extends ParentClassWithToStringMixedReturn
{
    public function __toString()
    {
        return 'value';
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\ClassMethod\DowngradeStringReturnTypeOnToStringRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\ClassMethod\DowngradeStringReturnTypeOnToStringRector\Source\ParentClassWithToStringMixedReturn;

// @see https://3v4l.org/IrE2q#v7.4.33
class WithParentMixedReturn extends ParentClassWithToStringMixedReturn
{
    public function __toString(): string
    {
        return 'value';
    }
}

?>
