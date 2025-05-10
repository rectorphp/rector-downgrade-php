<?php

namespace Rector\Tests\DowngradePhp80\Rector\Instanceof_\DowngradeInstanceofStringableRector\Fixture;

class ExactlyObjectType
{
    public function run(object $obj)
    {
        return $obj instanceof \Stringable;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Instanceof_\DowngradeInstanceofStringableRector\Fixture;

class ExactlyObjectType
{
    public function run(object $obj)
    {
        return method_exists($obj, '__toString');
    }
}

?>
