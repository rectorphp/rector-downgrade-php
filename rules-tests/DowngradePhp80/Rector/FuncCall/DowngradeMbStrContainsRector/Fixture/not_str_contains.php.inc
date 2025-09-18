<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        return ! str_contains('😊abc', 'b😊');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsWithMultibyteNeedleRector\Fixture;

final class NoStrContains
{
    public function run()
    {
        return mb_strpos('😊abc', 'b😊') === false;
    }
}

?>
