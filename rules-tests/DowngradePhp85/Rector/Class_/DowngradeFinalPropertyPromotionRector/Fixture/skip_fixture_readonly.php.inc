<?php

namespace Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\Fixture;

class SkipFixtureReadonly
{
    public function __construct(readonly string $id)
    {
    }
}

?>
