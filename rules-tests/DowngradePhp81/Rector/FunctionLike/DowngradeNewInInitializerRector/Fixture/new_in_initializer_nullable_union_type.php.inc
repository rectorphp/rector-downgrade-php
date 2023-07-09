<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInInitializerNullableUnionType
{
    public function __construct(public Foo|stdClass|null $obj = new stdClass)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class NewInInitializerNullableUnionType
{
    public function __construct(public Foo|stdClass|null $obj = null)
    {
        $this->obj = $obj ?? new stdClass;
    }
}

?>
