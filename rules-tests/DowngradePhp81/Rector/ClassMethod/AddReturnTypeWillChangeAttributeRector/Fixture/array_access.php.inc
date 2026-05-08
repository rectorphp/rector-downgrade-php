<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class ArrayAccessClass implements \ArrayAccess
{
    public function offsetGet($offset)
    {
    }

    public function offsetExists($offset)
    {
    }

    public function offsetSet($offset, $value)
    {
    }

    public function offsetUnset($offset)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class ArrayAccessClass implements \ArrayAccess
{
    #[\ReturnTypeWillChange]
    public function offsetGet($offset)
    {
    }

    #[\ReturnTypeWillChange]
    public function offsetExists($offset)
    {
    }

    #[\ReturnTypeWillChange]
    public function offsetSet($offset, $value)
    {
    }

    #[\ReturnTypeWillChange]
    public function offsetUnset($offset)
    {
    }
}

?>
