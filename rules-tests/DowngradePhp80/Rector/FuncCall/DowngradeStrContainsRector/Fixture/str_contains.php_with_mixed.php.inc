<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class StrContainsPhpWithMixed
{
    public function run($haystack, $needle)
    {
        str_contains($haystack, 'ab');
        str_contains('abc', $needle);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeStrContainsRector\Fixture;

final class StrContainsPhpWithMixed
{
    public function run($haystack, $needle)
    {
        strpos($haystack, 'ab') !== false;
        strpos('abc', $needle) !== false;
    }
}

?>
