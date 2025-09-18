<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetVariableStrpos
{
    public function run()
    {
        $offset = 1;
        $isMatch = str_contains(mb_substr('😊abc', $offset), '😊a');
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetVariableStrpos
{
    public function run()
    {
        $offset = 1;
        $isMatch = mb_strpos('😊abc', '😊a', $offset) !== false;
    }
}
?>
