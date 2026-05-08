<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class ArrayAccessWithReturnType implements \ArrayAccess
{
    public function offsetGet($offset): mixed
    {
    }

    public function offsetExists($offset): bool
    {
    }

    public function offsetSet($offset, $value): void
    {
    }

    public function offsetUnset($offset): void
    {
    }
}
