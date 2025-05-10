<?php

namespace Rector\Tests\DowngradePhp80\Rector\Instanceof_\DowngradeInstanceofStringableRector\Fixture;

class SkipDifferentObject
{
    public function run($obj)
    {
        return $obj instanceof \stdClass;
    }
}
