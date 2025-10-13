<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * falsy concat become empty string
 */
class SkipWithConcat
{
    public function run()
    {
        return substr('a', 2) . substr('b', 2);
    }
}
