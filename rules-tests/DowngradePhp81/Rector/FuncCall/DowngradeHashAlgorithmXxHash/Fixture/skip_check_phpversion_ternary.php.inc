<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class SkipCheckPHPVersionTernary
{
    public function run($value)
    {
        return PHP_VERSION_ID >= 80100
            ? hash( 'xxh128', $value )
            : hash( 'md4', $value );
    }
}
