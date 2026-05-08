<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeStringable implements \Stringable
{
    public function __toString()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeStringable implements \Stringable
{
    #[\ReturnTypeWillChange]
    public function __toString()
    {
    }
}

?>
