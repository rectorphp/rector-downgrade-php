<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$value = "hello world";
$result = $value
    |> function3(...)
    |> function2(...)
    |> function1(...);

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$value = "hello world";
$result1 = function3($value);
$result2 = function2($result1);
$result = function1($result2);

?>
