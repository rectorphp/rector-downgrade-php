<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use ArrayIterator;

class CombinedItemsClass
{
    public function run()
    {
        $parts = ['apple', 'pear'];
        $fruits = ['banana', 'orange', ...$parts, 'watermelon', ...new ArrayIterator(['durian', 'kiwi'])];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use ArrayIterator;

class CombinedItemsClass
{
    public function run()
    {
        $parts = ['apple', 'pear'];
        $fruits = array_merge(['banana', 'orange'], $parts, ['watermelon'], iterator_to_array(new ArrayIterator(['durian', 'kiwi'])));
    }
}

?>
