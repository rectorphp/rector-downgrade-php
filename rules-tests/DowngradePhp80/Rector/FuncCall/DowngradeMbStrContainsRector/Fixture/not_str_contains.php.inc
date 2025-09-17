<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        return ! str_contains('abc', 'b');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        return mb_strpos('abc', 'b') === false;
    }
}

?>
