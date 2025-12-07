<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$func = 'trim';
$result = "  hello  " |> $func(...);

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

$func = 'trim';
$result = $func("  hello  ");

?>