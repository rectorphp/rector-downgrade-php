<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipTernaryFalsy
{
    public function run()
    {
        return substr('a', 2) ?: 'default';
    }
}
