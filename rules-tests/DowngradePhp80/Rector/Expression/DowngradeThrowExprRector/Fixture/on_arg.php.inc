<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class OnArg
{
    public function run()
    {
        $this->setImageResource(imagecreatefromstring(ob_get_clean()) ?: throw new Nette\ShouldNotHappenException());
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class OnArg
{
    public function run()
    {
        $arg = imagecreatefromstring(ob_get_clean());
        if (!$arg) {
            throw new Nette\ShouldNotHappenException();
        }
        $this->setImageResource($arg);
    }
}

?>
