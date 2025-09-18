<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetExpressionStrpos
{
    public function run()
    {
        $offset = 1;
        $isMatch = str_contains(mb_substr('😊abc', $offset + 1), '😊a');
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

class OffsetExpressionStrpos
{
    public function run()
    {
        $offset = 1;
        $isMatch = mb_strpos('😊abc', '😊a', $offset + 1) !== false;
    }
}
?>