<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp72\Rector\ConstFetch\DowngradePhp72JsonConstRector\Fixture;

class SkipBitwiseDifferentConstant
{
    public function run($argument)
    {
        $argument = json_encode($argument, JSON_HEX_TAG | JSON_PRETTY_PRINT);
    }
}
