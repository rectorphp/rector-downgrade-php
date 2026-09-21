<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

$callable = fn (): int => 1;
$untyped = fn () => throw new \RuntimeException();
