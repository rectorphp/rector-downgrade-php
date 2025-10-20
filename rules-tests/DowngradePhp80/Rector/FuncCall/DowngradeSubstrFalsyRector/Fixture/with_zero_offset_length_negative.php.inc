<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * @see https://3v4l.org/lv13M#v7.4.33
 */
class WithZeroOffsetLengthNegative
{
    public function run(string $name)
    {
        return substr($name, 0, -5);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * @see https://3v4l.org/lv13M#v7.4.33
 */
class WithZeroOffsetLengthNegative
{
    public function run(string $name)
    {
        return (string) substr($name, 0, -5);
    }
}

?>
