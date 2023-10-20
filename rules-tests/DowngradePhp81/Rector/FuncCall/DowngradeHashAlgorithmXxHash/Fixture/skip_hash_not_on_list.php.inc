<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class SkipHashNotOnList
{
    public function run($arg)
    {
        return hash($arg, 'some-data-to-hash');
    }
}
