<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class ArrayAccessAlreadyAttributed implements \ArrayAccess
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
