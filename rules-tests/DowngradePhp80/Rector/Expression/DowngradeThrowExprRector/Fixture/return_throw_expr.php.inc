<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnThrowExpr
{
    public function run()
    {
        return throw new \InvalidArgumentException();
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnThrowExpr
{
    public function run()
    {
        throw new \InvalidArgumentException();
    }
}

?>
