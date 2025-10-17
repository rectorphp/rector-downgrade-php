<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * zero offset with postive length can't be false
 */
class SkipZeroOffsetWithPositiveLength
{
    public function run(string $name)
    {
        return substr($name, 0, 10);
    }
}
