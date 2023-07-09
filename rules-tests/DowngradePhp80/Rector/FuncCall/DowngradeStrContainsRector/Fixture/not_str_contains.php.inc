<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

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

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        return strpos('abc', 'b') === false;
    }
}

?>
