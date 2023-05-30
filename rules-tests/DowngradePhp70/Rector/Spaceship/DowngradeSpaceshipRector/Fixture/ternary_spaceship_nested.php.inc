<?php

namespace Rector\Tests\DowngradePhp70\Rector\Spaceship\DowngradeSpaceshipRector\Fixture;

final class TernarySpaceshipNested
{
    private $a;

    private $b;

    public function run()
    {
        return $this->a <=> $this->b ?: $this->b <=> $this->a;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\Spaceship\DowngradeSpaceshipRector\Fixture;

final class TernarySpaceshipNested
{
    private $a;

    private $b;

    public function run()
    {
        $battleShipcompare = function ($left, $right) {
            if ($left === $right) {
                return 0;
            }
            return $left < $right ? -1 : 1;
        };
        return $battleShipcompare($this->a, $this->b) ?: $battleShipcompare($this->b, $this->a);
    }
}

?>
