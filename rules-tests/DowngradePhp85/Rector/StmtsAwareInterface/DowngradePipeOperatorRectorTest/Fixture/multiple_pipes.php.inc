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
$result = function3($value);
$result = function2($result);
$result = function1($result);

?>