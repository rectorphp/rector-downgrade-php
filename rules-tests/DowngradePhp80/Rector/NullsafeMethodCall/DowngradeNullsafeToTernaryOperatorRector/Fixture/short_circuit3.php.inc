<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit3
{
    public function run(bool $param)
    {
        return $this->clock?->now->format;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit3
{
    public function run(bool $param)
    {
        return ($nullsafeVariable14 = $this->clock) ? $nullsafeVariable14->now->format : null;
    }
}

?>
