<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAllRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        return array_all($animals, fn($animal) => str_starts_with($animal, 'c'));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAllRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        $found = true;
        foreach ($animals as $animal) {
            if (!str_starts_with($animal, 'c')) {
                $found = false;
                break;
            }
        }
        return $found;
    }
}

?>
