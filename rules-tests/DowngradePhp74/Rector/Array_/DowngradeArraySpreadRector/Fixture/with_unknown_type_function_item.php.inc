<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

class WithUnknownTypeFunctionItem
{
    function getArrayOrTraversable()
    {
        return ['apple', 'pear'];
    }

    public function run()
    {
        $fruits = ['banana', 'orange', ...$this->getArrayOrTraversable(), 'watermelon'];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

class WithUnknownTypeFunctionItem
{
    function getArrayOrTraversable()
    {
        return ['apple', 'pear'];
    }

    public function run()
    {
        $fruits = array_merge(['banana', 'orange'], is_array($this->getArrayOrTraversable()) ? $this->getArrayOrTraversable() : iterator_to_array($this->getArrayOrTraversable()), ['watermelon']);
    }
}

?>
