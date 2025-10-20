<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * negation can be false or empty string ""
 */
class SkipNegated
{
    public function run()
    {
        return ! substr('a', 2);
    }
}
