<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class Fixture
{
    protected final $foo = 'bar';
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class Fixture
{
    /**
     * @final
     */
    protected $foo = 'bar';
}

?>
