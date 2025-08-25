<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class SkipCheckVersionCompareOnIf
{
    public function run_v()
    {
        if ( version_compare( PHP_VERSION, '8.1', '>=' ) ) {
            return hash( 'xxh128', $value );
        }

        return hash( 'md4', $value );
    }

    public function run_v2()
    {
        if (version_compare( PHP_VERSION, '8.1', '>=' ) ) {
            $hash = hash( 'xxh128', $value );
        } else {
            $hash = hash( 'md4', $value );
        }

        return $hash;
    }
}
