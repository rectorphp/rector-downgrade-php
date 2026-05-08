<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeCountable implements \Countable
{
    public function count()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\ClassMethod\AddReturnTypeWillChangeAttributeRector\Fixture;

class SomeCountable implements \Countable
{
    #[\ReturnTypeWillChange]
    public function count()
    {
    }
}

?>
