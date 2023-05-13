<?php

namespace Rector\Tests\DowngradePhp70\Rector\Expression\DowngradeDefineArrayConstantRector\Fixture;

function skipFirstClassCallable()
{
    $firstClassCallable = define(...);
}
