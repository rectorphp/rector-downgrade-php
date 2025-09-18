<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetVariableZeroStrpos
{
    public function run()
    {
        $offset = 0;
        $isMatch = str_contains(mb_substr('😊abc', $offset), '😊a');
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetVariableZeroStrpos
{
    public function run()
    {
        $offset = 0;
        $isMatch = mb_strpos('😊abc', '😊a', $offset) !== false;
    }
}
?>