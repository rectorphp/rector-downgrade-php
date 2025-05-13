<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\FuncCall\DowngradeArrayFirstLastRector\Fixture;

final class Fixture
{
    public function run(array $array)
    {
        echo array_first($array);
        echo array_last($array);
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\FuncCall\DowngradeArrayFirstLastRector\Fixture;

final class Fixture
{
    public function run(array $array)
    {
        echo $array[array_key_first($array)];
        echo $array[array_key_last($array)];
    }
}

?>
