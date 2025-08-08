<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayFindRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        return array_find($animals, fn($animal) => str_starts_with($animal, 'c'));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayFindRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        $found = null;
        foreach ($animals as $animal) {
            if (str_starts_with($animal, 'c')) {
                $found = $animal;
                break;
            }
        }
        return $found;
    }
}

?>
