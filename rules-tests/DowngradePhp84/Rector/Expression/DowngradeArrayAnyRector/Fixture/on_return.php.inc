<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAnyRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        return array_any($animals, fn($animal) => str_starts_with($animal, 'c'));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAnyRector\Fixture;

class OnReturn
{
    public function run(array $animals)
    {
        $found = false;
        foreach ($animals as $animal) {
            if (str_starts_with($animal, 'c')) {
                $found = true;
                break;
            }
        }
        return $found;
    }
}

?>
