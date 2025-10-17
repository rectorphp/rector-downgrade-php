<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class Fixture
{
    public function run()
    {
        return substr("a", 2);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class Fixture
{
    public function run()
    {
        return (string) substr("a", 2);
    }
}

?>
