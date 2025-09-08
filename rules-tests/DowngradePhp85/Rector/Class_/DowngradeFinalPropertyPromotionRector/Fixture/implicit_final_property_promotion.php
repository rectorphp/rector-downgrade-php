<?php
namespace Rector\Tests\DowngradeFinalPropertyPromotionRector\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

class ImplicitFinalPropertyPromotion
{
    public function __construct(final string $foo)
    {
    }
}
?>
-----
<?php
namespace Rector\Tests\DowngradeFinalPropertyPromotionRector\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

class ImplicitFinalPropertyPromotion
{
    public function __construct(
         /**
           * @final
           */
         public string $foo
    )
    {
    }
}
