<?php

namespace Rector\Tests\DowngradePhp71\Rector\StaticCall\DowngradeClosureFromCallableRector\Fixture;

function OnReturn()
{
    return  \Closure::fromCallable('strtolower');;
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\StaticCall\DowngradeClosureFromCallableRector\Fixture;

function OnReturn()
{
    $callable = 'strtolower';
    return  function () use ($callable) {
        return $callable(...func_get_args());
    };
}

?>
