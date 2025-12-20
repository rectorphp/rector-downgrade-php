<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit5
{
    public function run(bool $param)
    {
        return $this->clock?->now()->format;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit5
{
    public function run(bool $param)
    {
        return ($nullsafeVariable1 = $this->clock) ? $nullsafeVariable1->now()->format : null;
    }
}

?>
