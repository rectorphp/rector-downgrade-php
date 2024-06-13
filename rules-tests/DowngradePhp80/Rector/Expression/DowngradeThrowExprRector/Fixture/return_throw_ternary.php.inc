<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnThrowTernary
{
    public function run($variable)
    {
        return $variable ?: throw new \InvalidArgumentException();
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnThrowTernary
{
    public function run($variable)
    {
        if (!$variable) {
            throw new \InvalidArgumentException();
        }
        return $variable;
    }
}

?>
