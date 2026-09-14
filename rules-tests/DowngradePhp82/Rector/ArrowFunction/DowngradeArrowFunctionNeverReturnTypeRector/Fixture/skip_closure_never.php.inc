<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

$callable = function (): never {
    throw new \RuntimeException();
};

function fail(): never
{
    throw new \RuntimeException();
}
