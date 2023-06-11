<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;

final class BareString
{
    public function run()
    {
        echo 'abcdef'[-2];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;

final class BareString
{
    public function run()
    {
        echo substr('abcdef', -2, 1);
    }
}

?>
