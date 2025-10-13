<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * empty can be false or empty string ""
 */
class SkipEmpty
{
    public function run()
    {
        return empty(substr("a", 2));
    }
}
