<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\Expression\DowngradeVoidCastRector\Fixture;

final class SkipDifferentCast
{
    public function run()
    {
        (int) call();
    }
}

?>
