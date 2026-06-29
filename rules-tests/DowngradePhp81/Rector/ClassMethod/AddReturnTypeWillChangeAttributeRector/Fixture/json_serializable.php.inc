<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeJsonSerializable implements \JsonSerializable
{
    public function jsonSerialize()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeJsonSerializable implements \JsonSerializable
{
    #[\ReturnTypeWillChange]
    public function jsonSerialize()
    {
    }
}

?>
