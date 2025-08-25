<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class SkipCheckVersionCompareTernary2
{
    public function run_v()
    {
        return version_compare(PHP_VERSION, '8.1','<')
            ? hash( 'md4', $value )
            : hash( 'xxh128', $value );
    }
}
