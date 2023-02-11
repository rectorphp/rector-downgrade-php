<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\ReturnNullable;

final class SkipReturnNonNullableOverrideNullable implements ReturnNullable
{
    public function run(): array
    {
        return ['test'];
    }
}
