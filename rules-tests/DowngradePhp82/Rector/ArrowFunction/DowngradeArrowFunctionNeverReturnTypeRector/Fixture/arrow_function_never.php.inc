<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

$callable = fn (): never => throw new \RuntimeException();

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\ArrowFunction\DowngradeArrowFunctionNeverReturnTypeRector\Fixture;

$callable = fn () => throw new \RuntimeException();

?>
