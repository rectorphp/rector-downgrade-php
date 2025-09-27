<?php

namespace Rector\Tests\Php84\Rector\FuncCall\RoundingModeEnumRector;

round(precision: 0, mode: \RoundingMode::HalfAwayFromZero, value: 1.5);

?>
-----
<?php

namespace Rector\Tests\Php84\Rector\FuncCall\RoundingModeEnumRector;

round(precision: 0, mode: \PHP_ROUND_HALF_UP, value: 1.5);

?>
