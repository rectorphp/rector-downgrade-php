<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnTernary
{
    public function run($res)
    {
        return $res === \false ? throw new Nette\ShouldNotHappenException() : $res;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class ReturnTernary
{
    public function run($res)
    {
        if ($res === \false) {
            throw new Nette\ShouldNotHappenException();
        }
        return $res;
    }
}

?>
