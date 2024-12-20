<?php

namespace Rector\Tests\Php84\Rector\FuncCall\RoundingModeEnumRector;


$mode = \RoundingMode::HalfTowardsZero;

round(1.5, 0, $mode);

?>
