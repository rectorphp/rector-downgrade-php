<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * zero offset with no length can't be false
 */
class SkipZeroOffsetWithNoLength
{
    public function run(string $name)
    {
        return substr($name, 0);
    }
}
