<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class SomeMethodCall
{
    public function foo(stdClass $obj = new stdClass)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class SomeMethodCall
{
    public function foo(stdClass $obj = null)
    {
        $obj ??= new stdClass;
    }
}

?>
