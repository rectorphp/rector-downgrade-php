<?php

namespace Rector\Tests\DowngradePhp84\Rector\Expression\DowngradeArrayAnyRector\Fixture;

class WithKey
{
    public function run(array $animals)
    {
        $found = array_find_key($animals, fn($animal, $key) => str_starts_with($animal, 'c') && $key > 0);
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
        $found = null;
        foreach ($animals as $key => $animal) {
            if (str_starts_with($animal, 'c') && $key > 0) {
                $found = $key;
                break;
            }
        }
    }
}

?>
