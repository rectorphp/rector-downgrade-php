<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayFindKeyRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        return array_find_key($animals, fn($animal) => str_starts_with($animal, 'c'));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayFindKeyRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        $found = null;
        foreach ($animals as $idx => $animal) {
            if (str_starts_with($animal, 'c')) {
                $found = $idx;
                break;
            }
        }
        return $found;
    }
}

?>
