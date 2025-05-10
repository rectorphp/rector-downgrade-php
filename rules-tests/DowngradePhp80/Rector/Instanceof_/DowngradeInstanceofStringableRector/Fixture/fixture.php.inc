<?php

namespace Rector\Tests\DowngradePhp80\Rector\Instanceof_\DowngradeInstanceofStringableRector\Fixture;

class Fixture
{
    public function run($obj)
    {
        return $obj instanceof \Stringable;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Instanceof_\DowngradeInstanceofStringableRector\Fixture;

class Fixture
{
    public function run($obj)
    {
        return is_object($obj) && method_exists($obj, '__toString');
    }
}

?>
