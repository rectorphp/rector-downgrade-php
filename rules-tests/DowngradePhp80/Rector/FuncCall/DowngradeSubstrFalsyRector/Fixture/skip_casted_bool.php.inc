<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipCastedBool
{
    public function run(string $name)
    {
        return (bool) substr($name, 2);
    }
}
