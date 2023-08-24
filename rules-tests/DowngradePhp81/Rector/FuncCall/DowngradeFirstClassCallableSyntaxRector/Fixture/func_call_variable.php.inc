<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeFirstClassCallableSyntaxRector\Fixture;

class FuncCallInVariable
{
    public function run()
    {
        $fn = 'strlen';
        $cb = $fn(...);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeFirstClassCallableSyntaxRector\Fixture;

class FuncCallInVariable
{
    public function run()
    {
        $fn = 'strlen';
        $cb = \Closure::fromCallable($fn);
    }
}

?>
