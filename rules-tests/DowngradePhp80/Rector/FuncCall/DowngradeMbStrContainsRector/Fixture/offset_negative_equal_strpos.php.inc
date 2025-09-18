<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetNegativeStrpos
{
    public function run()
    {
        $isMatch = str_contains(mb_substr('😊abc', -1), '😊a');
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetNegativeStrpos
{
    public function run()
    {
        $isMatch = mb_strpos('😊abc', '😊a', -1) !== false;
    }
}
?>