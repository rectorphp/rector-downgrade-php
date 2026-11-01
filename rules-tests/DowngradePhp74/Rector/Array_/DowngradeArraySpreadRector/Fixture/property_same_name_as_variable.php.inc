<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use ArrayIterator;

final class PropertySameNameAsVariable
{
    private ArrayIterator $items;

    public function run()
    {
        $items = ['apple'];

        return [...$this->items, ...$items];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use ArrayIterator;

final class PropertySameNameAsVariable
{
    private ArrayIterator $items;

    public function run()
    {
        $items = ['apple'];

        return array_merge(iterator_to_array($this->items), $items);
    }
}

?>
