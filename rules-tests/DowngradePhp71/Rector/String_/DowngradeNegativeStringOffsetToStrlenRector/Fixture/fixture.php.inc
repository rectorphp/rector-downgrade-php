<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;

class Fixture
{
    public function run($var)
    {
        echo strpos($var, 'b', -3);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;

class Fixture
{
    public function run($var)
    {
        echo strpos($var, 'b', strlen($var) - 3);
    }
}

?>
