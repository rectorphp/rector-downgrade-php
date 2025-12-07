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
$result = trim($data);
$result = strtoupper($result);
$result = (fn($str) => str_replace('WORLD', 'PHP', $str))($result);
$processed = addslashes($result);
?>