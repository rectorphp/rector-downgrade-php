<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

final class OnProperty
{
    public (A&B)|C $foo;
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture;

final class OnProperty
{
    /**
     * @var (\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\A & \Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\B)|\Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeUnionIntersectionRector\Fixture\C
     */
    public $foo;
}

?>
