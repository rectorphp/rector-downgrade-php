<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class SkipCheckVersionCompareTernary
{
    public function run_v()
    {
        $value = version_compare(PHP_VERSION, '8.1','>=')
            ? hash( 'xxh128', $value )
            : hash( 'md4', $value );

        $value = version_compare(PHP_VERSION, '8.1','<')
            ? hash( 'md4', $value )
            : hash( 'xxh128', $value );
    }
}
