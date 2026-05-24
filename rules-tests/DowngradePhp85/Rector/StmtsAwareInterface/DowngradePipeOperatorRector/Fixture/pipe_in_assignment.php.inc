<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$value = " test ";
$result = $value |> trim(...) |> strtoupper(...);

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$value = " test ";
$result = trim($value);
$result = strtoupper($result);

?>