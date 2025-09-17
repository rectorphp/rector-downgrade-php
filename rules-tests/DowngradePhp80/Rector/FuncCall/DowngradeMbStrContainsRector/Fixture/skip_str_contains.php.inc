<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

final class StrContains
{
    public function run()
    {
        str_contains('😊abc', 'b');
    }
}

?>
