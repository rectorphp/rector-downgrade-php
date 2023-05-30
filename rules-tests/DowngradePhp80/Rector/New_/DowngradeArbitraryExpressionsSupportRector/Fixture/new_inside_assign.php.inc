<?php

namespace Rector\Tests\DowngradePhp80\Rector\New_\DowngradeArbitraryExpressionsSupportRector\Fixture;

final class NewInsideAssign
{
    public function run()
    {
        $object = new ($assignHere = \stdClass::class);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\New_\DowngradeArbitraryExpressionsSupportRector\Fixture;

final class NewInsideAssign
{
    public function run()
    {
        $assignHere = \stdClass::class;
        $object = new $assignHere();
    }
}

?>
