<?php

round(1.5, 0, RoundingMode::HalfAwayFromZero);

?>
-----
<?php

round(1.5, 0, \PHP_ROUND_HALF_UP);

?>
