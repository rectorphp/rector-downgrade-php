<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipInBinaryOp
{
    public function run($a)
    {
        return substr("a", 2) && $a === true;
    }
}
