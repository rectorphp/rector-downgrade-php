<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipDifferentFuncCall
{
    public function run()
    {
        return strlen('a');
    }
}
