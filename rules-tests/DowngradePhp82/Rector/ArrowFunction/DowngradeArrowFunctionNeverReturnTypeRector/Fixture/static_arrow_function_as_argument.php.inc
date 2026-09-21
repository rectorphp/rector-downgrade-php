<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

function run(int $code)
{
    return array_map(static fn (int $item): never => throw new \LogicException('boom', $code), [1]);
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

function run(int $code)
{
    return array_map(static fn (int $item) => throw new \LogicException('boom', $code), [1]);
}

?>
