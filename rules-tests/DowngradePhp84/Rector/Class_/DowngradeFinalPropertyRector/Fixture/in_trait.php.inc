<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

trait InTrait
{
    final protected string $foo = 'bar';
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

trait InTrait
{
    /**
     * @final
     */
    protected string $foo = 'bar';
}

?>
