<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipComparedToFalse
{
    public function run(string $name)
    {
        substr($name, 2) == false;
        substr($name, 2) === false;
    }
}
