<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source;

class ClassWithArrayConstant
{
    public const ITEMS = ['a', SomeTokens::TOKEN];
}
