<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInInitializerUnionType
{
    public function __construct(public Foo|stdClass $obj = new stdClass)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInInitializerUnionType
{
    public function __construct(public Foo|stdClass|null $obj = null)
    {
        $this->obj = $obj ?? new stdClass;
    }
}

?>
