<?php

namespace Rector\Tests\DowngradePhp81\Rector\LNumber\DowngradeOctalNumberRector\Fixture;

final class BiggerOu
{
    public function run()
    {
        return 0O777;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\LNumber\DowngradeOctalNumberRector\Fixture;

final class BiggerOu
{
    public function run()
    {
        return 0777;
    }
}

?>
