<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class SkipHasAllowedAlgorithm
{
    public function run()
    {
        return hash('sha1', 'some-data-to-hash');
    }
}
