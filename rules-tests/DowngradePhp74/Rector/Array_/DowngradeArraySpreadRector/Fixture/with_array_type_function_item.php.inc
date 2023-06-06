<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

class WithArrayTypeFunctionItem
{
    function getArray(): array
    {
        return ['apple', 'pear'];
    }

    public function run()
    {
        $fruits = ['banana', 'orange', ...$this->getArray(), 'watermelon'];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

class WithArrayTypeFunctionItem
{
    function getArray(): array
    {
        return ['apple', 'pear'];
    }

    public function run()
    {
        $fruits = array_merge(['banana', 'orange'], $this->getArray(), ['watermelon']);
    }
}

?>
