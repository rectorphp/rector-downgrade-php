<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp83\Rector\ClassConstFetch\DowngradeDynamicClassConstFetchRector\Fixture;

class SkipNamedClassConstFetch
{
    public const FOO = 'foo';

    public function run()
    {
        return self::FOO;
    }
}
