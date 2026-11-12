<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source;

class ClassWithGlobalConstants
{
    public const ITEMS = [PHP_EOL, \PHP_VERSION, T_STRING, true, null, UNKNOWN_CONSTANT];
}
