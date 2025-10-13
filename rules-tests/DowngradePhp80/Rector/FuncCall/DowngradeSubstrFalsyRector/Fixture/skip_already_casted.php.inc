<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipAlreadyCasted
{
    public function run()
    {
        return (string) substr("a", 2);
    }
}
