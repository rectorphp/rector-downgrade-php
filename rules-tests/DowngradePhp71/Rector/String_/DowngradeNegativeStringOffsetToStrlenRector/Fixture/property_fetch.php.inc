<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;
final class SomePropertyFetch
{
    private $var;

    public function run()
    {
        $this->var = 'abc';
        echo $this->var[-2];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector\Fixture;
final class SomePropertyFetch
{
    private $var;

    public function run()
    {
        $this->var = 'abc';
        echo substr($this->var, -2, 1);
    }
}

?>
