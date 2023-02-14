<?php

namespace Rector\Tests\DowngradePhp80\Rector\ClassMethod\DowngradeTrailingCommasInParamUseRector\Fixture;

class SkipInArgs
{
    public function run(): void
    {
        var_dump('foo',);
    }
}
