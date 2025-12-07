<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit
{
    public function run(bool $param)
    {
        return $this->clock?->now()->format('U.u');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit
{
    public function run(bool $param)
    {
        return ($nullsafeVariable13 = $this->clock) ? $nullsafeVariable13->now()->format('U.u') : null;
    }
}

?>
