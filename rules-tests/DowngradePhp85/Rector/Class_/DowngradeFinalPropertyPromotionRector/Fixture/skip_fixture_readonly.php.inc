<?php

namespace Rector\Tests\DowngradeFinalPropertyPromotionRector\Rector\Class_\DowngradePropertyPromotionRector\Fixture;

class SkipFixtureReadonly
{
    public function __construct(readonly string $id)
    {
    }
}

?>
