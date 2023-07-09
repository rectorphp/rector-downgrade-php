<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        ! str_contains('abc', 'b');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        strpos('abc', 'b') === false;
    }
}

?>
