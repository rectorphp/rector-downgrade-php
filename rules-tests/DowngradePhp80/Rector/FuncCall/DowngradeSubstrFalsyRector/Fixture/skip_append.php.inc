<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipAppend
{
    public function run(string $a)
    {
        $a .=substr('a', 2);

        return $a;
    }
}
