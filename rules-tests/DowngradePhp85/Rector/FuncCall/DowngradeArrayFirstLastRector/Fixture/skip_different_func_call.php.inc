<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\FuncCall\DowngradeArrayFirstLastRector\Fixture;

final class SkipDifferentFuncCall
{
    public function run()
    {
        return strlen('test');
    }
}

?>
