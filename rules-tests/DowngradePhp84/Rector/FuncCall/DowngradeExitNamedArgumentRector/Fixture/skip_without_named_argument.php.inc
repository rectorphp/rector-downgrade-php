<?php

namespace Rector\Tests\DowngradePhp84\Rector\FuncCall\DowngradeExitNamedArgumentRector\Fixture;

final class SkipWithoutNamedArgument
{
    public function run()
    {
        exit(1);
        die('failure');
        custom(status: 1);
    }
}
