<?php

namespace Rector\Tests\DowngradeFinalPropertyPromotionRector\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

class Fixture
{
    public function __construct(
        final public string $id
    ) {}
}

?>
-----
<?php

namespace Rector\Tests\DowngradeFinalPropertyPromotionRector\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

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
