<?php

namespace Rector\Tests\DowngradePhp71\Rector\StaticCall\DowngradeClosureFromCallableRector\Fixture;

function OnReturnInsideArray()
{
    return [
        \Closure::fromCallable('strtolower')
    ];
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\StaticCall\DowngradeClosureFromCallableRector\Fixture;

function OnReturnInsideArray()
{
    $callable = 'strtolower';
    return [
        function () use ($callable) {
            return $callable(...func_get_args());
        }
    ];
}

?>
