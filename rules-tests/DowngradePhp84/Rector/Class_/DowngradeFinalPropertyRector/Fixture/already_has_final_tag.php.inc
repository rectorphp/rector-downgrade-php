<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class AlreadyHasFinalTag
{
    /**
     * @final
     */
    final protected $foo = 'bar';
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class AlreadyHasFinalTag
{
    /**
     * @final
     */
    protected $foo = 'bar';
}

?>
