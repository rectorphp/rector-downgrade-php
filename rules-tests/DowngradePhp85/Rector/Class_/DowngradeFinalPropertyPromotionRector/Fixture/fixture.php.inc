<?php

namespace Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\Fixture;

class Fixture
{
    public function __construct(
        final public string $id
    ) {}
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\Fixture;

class Fixture
{
    public function __construct(
        /**
         * @final
         */
        public string $id
    ) {}
}

?>
