<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$data = "  Hello, World!  ";
$processed = $data
    |> trim(...)
    |> strtoupper(...)
    |> (fn($str) => str_replace('WORLD', 'PHP', $str))
    |> addslashes(...);
?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$data = "  Hello, World!  ";
$result1 = trim($data);
$result2 = strtoupper($result1);
$result3 = (fn($str) => str_replace('WORLD', 'PHP', $str))($result2);
$processed = addslashes($result3);
?>