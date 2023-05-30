<?php

namespace Rector\Tests\DowngradePhp80\Rector\New_\DowngradeArbitraryExpressionsSupportRector\Fixture;

$justInstanceof = new \stdClass();
var_dump($justInstanceof instanceof (\stdClass::class));

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\New_\DowngradeArbitraryExpressionsSupportRector\Fixture;

$justInstanceof = new \stdClass();
$className = \stdClass::class;
var_dump($justInstanceof instanceof $className);

?>
