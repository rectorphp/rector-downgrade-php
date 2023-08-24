<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeFirstClassCallableSyntaxRector\Fixture;

class StaticCallUsage
{
    public function run(): \Closure
    {
        return StaticCallUsage::dump(...);
    }

    public static function dump(...$args): void
    {
        var_dump(...$args);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeFirstClassCallableSyntaxRector\Fixture;

class StaticCallUsage
{
    public function run(): \Closure
    {
        return \Closure::fromCallable([StaticCallUsage::class, 'dump']);
    }

    public static function dump(...$args): void
    {
        var_dump(...$args);
    }
}

?>
