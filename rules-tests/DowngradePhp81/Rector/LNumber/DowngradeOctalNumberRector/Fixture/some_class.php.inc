<?php

namespace Rector\Tests\DowngradePhp81\Rector\LNumber\DowngradeOctalNumberRector\Fixture;

class SomeClass
{
    public function run()
    {
        return 0o777;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\LNumber\DowngradeOctalNumberRector\Fixture;

class SomeClass
{
    public function run()
    {
        return 0777;
    }
}

?>
