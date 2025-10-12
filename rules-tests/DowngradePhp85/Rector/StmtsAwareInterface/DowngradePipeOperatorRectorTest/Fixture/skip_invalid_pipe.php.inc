<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

// This should be skipped as the right side is not callable
$result = "hello" |> "not_callable";

?>