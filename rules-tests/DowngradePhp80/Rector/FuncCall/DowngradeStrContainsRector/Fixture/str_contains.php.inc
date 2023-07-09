<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class StrContains
{
    public function run()
    {
        str_contains('abc', 'b');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class StrContains
{
    public function run()
    {
        strpos('abc', 'b') !== false;
    }
}

?>
