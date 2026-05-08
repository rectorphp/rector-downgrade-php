<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeIterator implements \Iterator
{
    public function current()
    {
    }

    public function key()
    {
    }

    public function next()
    {
    }

    public function rewind()
    {
    }

    public function valid()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeIterator implements \Iterator
{
    #[\ReturnTypeWillChange]
    public function current()
    {
    }

    #[\ReturnTypeWillChange]
    public function key()
    {
    }

    #[\ReturnTypeWillChange]
    public function next()
    {
    }

    #[\ReturnTypeWillChange]
    public function rewind()
    {
    }

    #[\ReturnTypeWillChange]
    public function valid()
    {
    }
}

?>
