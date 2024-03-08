<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class InsideIfCond
{
    public function run($items)
    {
        if (array_key_last($items)) {
            return true;
        } else {
            return false;
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class InsideIfCond
{
    public function run($items)
    {
        end($items);
        if (key($items)) {
            reset($items);
            return true;
        } else {
            return false;
        }
    }
}

?>
