<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipDirectCond
{
    public function run(string $name)
    {
        if (substr($name, 2)) {
            return true;
        }
    }
}
