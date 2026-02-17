<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

function onReturnFunction(): (A&B)|C
{
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

/**
 * @return (\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\A & \Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\B)|\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\C
 */
function onReturnFunction()
{
}

?>
