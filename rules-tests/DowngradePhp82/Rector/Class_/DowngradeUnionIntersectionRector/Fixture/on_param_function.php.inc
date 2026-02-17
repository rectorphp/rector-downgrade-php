<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

function onParamFunction((A&B)|C $foo)
{
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

/**
 * @param (\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\A & \Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\B)|\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\C $foo
 */
function onParamFunction($foo)
{
}

?>
