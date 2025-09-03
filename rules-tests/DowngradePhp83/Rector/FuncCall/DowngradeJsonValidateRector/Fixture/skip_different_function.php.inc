<?php

namespace Rector\Tests\DowngradePhp83\Rector\FuncCall\DowngradeJsonValidateRector\Fixture;

class SkipDifferentFunction
{
    public function run($json)
    {
        echo strlen($json);
    }
}
