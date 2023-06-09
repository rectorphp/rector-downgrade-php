<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class InReturn
{
    public function run($items)
    {
        return array_key_last($items);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class InReturn
{
    public function run($items)
    {
        end($items);
        return key($items);
    }
}

?>
