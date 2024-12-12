<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector\Fixture;

// @see https://3v4l.org/POahP#v7.2.17
class MultiSpace
{
    public function run()
    {
        self::run('posts','units'  , );
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector\Fixture;

// @see https://3v4l.org/POahP#v7.2.17
class MultiSpace
{
    public function run()
    {
        self::run('posts','units');
    }
}

?>
