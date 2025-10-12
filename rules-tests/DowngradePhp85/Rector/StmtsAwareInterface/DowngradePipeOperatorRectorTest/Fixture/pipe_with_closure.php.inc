<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$result = "hello" |> (fn($x) => strtoupper($x)) |> (fn($y) => $y . '!');

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$result1 = (fn($x) => strtoupper($x))("hello");
$result = (fn($y) => $y . '!')($result1);

?>