<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

final class ArrowFunctionWithThrow
{
    public function run()
    {
        return fn () => throw new \LogicException('Lazy proxy has no initializer.');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

final class ArrowFunctionWithThrow
{
    public function run()
    {
        return function () {
            throw new \LogicException('Lazy proxy has no initializer.');
        };
    }
}

?>
