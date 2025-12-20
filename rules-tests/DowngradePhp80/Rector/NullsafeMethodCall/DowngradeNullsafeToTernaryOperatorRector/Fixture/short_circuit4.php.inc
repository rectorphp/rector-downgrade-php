<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit4
{
    public function run(bool $param)
    {
        return $this->clock?->now->format('U.u');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

final class ShortCircuit4
{
    public function run(bool $param)
    {
        return ($nullsafeVariable15 = $this->clock) ? $nullsafeVariable15->now->format('U.u') : null;
    }
}

?>
