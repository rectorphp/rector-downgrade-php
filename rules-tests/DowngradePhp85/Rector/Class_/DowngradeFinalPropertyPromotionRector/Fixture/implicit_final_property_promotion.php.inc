<?php

namespace Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\Fixture;

class ImplicitFinalPropertyPromotion
{
    public function __construct(final string $foo)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\Fixture;

class ImplicitFinalPropertyPromotion
{
    public function __construct(/**
     * @final
     */
    public string $foo)
    {
    }
}

?>
