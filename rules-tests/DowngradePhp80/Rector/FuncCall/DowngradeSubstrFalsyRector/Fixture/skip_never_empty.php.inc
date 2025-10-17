<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipNeverEmpty
{
    public function run()
    {
        return substr("abc", 2);
    }
}
