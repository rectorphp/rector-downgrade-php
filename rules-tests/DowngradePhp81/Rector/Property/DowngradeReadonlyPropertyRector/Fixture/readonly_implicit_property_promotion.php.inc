<?php

namespace Rector\Tests\DowngradePhp81\Rector\Property\DowngradeReadonlyPropertyRector\Fixture;

class ReadonlyImplicitPropertyPromotion
{
    public function __construct(
        readonly string $foo = 'foo'
    )
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\Property\DowngradeReadonlyPropertyRector\Fixture;

class ReadonlyImplicitPropertyPromotion
{
    public function __construct(
        public string $foo = 'foo'
    )
    {
    }
}

?>
