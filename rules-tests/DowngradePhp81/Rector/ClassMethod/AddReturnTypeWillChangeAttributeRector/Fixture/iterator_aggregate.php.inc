<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeIteratorAggregate implements \IteratorAggregate
{
    public function getIterator()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeIteratorAggregate implements \IteratorAggregate
{
    #[\ReturnTypeWillChange]
    public function getIterator()
    {
    }
}

?>
