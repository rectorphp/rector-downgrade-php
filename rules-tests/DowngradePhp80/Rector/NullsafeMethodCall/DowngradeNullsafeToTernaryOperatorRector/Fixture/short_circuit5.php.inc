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
        return ($nullsafeVariable16 = $this->clock) ? $nullsafeVariable16->now()->format : null;
    }
}

?>
