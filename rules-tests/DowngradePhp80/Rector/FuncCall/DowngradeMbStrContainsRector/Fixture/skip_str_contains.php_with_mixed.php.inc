<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

final class StrContainsPhpWithMixed
{
    public function run($haystack, $needle)
    {
        str_contains($haystack, 'ab');
        str_contains('😊abc', $needle);
    }
}

?>
