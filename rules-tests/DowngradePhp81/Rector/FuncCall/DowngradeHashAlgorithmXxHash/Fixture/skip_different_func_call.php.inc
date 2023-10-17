<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class SkipDifferentFuncCall
{
    public function run(string $data)
    {
        return strlen($data);
    }
}
