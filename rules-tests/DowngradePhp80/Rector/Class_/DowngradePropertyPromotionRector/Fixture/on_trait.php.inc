<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

trait OnTrait
{
    public function __construct(public float $value = 0.0)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

trait OnTrait
{
    public float $value = 0.0;
    public function __construct(float $value = 0.0)
    {
        $this->value = $value;
    }
}

?>
