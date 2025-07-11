<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAnyRector\Fixture;

class WithKey
{
    public function run(array $animals)
    {
        $found = array_all($animals, fn($animal, $key) => str_starts_with($animal, 'c') && $key > 0);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAnyRector\Fixture;

class WithKey
{
    public function run(array $animals)
    {
        $found = false;
        foreach ($animals as $key => $animal) {
            if (str_starts_with($animal, 'c') && $key > 0) {
                $found = true;
                break;
            }
        }
    }
}

?>
