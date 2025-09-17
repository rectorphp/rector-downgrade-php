<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

class IdenticalStrpos
{
    public function run()
    {
        $isMatch = !str_contains('abc😊', '😊a');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeMbStrContainsRector\Fixture;

class IdenticalStrpos
{
    public function run()
    {
        $isMatch = mb_strpos('abc😊', '😊a') === false;
    }
}

?>