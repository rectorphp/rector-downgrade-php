<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

class OffsetStrpos
{
    public function run()
    {
        $isMatch = str_contains(mb_substr('abc', 1), 'a');
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

class OffsetStrpos
{
    public function run()
    {
        $isMatch = mb_strpos('abc', 'a', 1) !== false;
    }
}
?>