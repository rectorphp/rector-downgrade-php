<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipAsArrayDimFetchDim
{
    public function run()
    {
        $data[substr('a', 2)] = 'foo';
        var_dump($data);
    }
}