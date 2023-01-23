<?php

namespace Rector\Tests\DowngradePhp73\Rector\Unset_\DowngradeTrailingCommasInUnsetRector\Fixture;

class Fixture
{
    public function run()
    {
        $a = '';
        unset($a, $b,);
        unset(
            $c,
            $d,
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\Unset_\DowngradeTrailingCommasInUnsetRector\Fixture;

class Fixture
{
    public function run()
    {
        $a = '';
        unset($a, $b);
        unset($c, $d);
    }
}

?>
