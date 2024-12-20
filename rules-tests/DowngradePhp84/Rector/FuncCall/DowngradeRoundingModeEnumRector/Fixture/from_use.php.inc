<?php

namespace Rector\Tests\Php84\Rector\FuncCall\RoundingModeEnumRector;

use RoundingMode;

round(1.5, 0, RoundingMode::HalfAwayFromZero);

?>
-----
<?php

namespace Rector\Tests\Php84\Rector\FuncCall\RoundingModeEnumRector;

use RoundingMode;

round(1.5, 0, \PHP_ROUND_HALF_UP);

?>
