<?php

namespace Rector\Tests\DowngradePhp81\Rector\LNumber\DowngradeOctalNumberRector\Fixture;

final class SkipAnotherValues
{
    public function run()
    {
        $result = '0O777';

        $next = '0o77Oo7';

        $binaryNumber = 0b1111;
    }
}

