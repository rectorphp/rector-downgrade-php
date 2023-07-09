<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInItnializer
{
    public function __construct(public stdClass $obj = new stdClass)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInItnializer
{
    public function __construct(public ?stdClass $obj = null)
    {
        $this->obj = $obj ?? new stdClass;
    }
}

?>
