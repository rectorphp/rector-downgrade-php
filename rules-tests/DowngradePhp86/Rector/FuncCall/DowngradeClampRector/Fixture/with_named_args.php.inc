<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp86\Rector\FuncCall\DowngradeClampRector\Fixture;

clamp(max: $max, value: $value, min: $min);

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp86\Rector\FuncCall\DowngradeClampRector\Fixture;

max($min, min($max, $value));

?>
