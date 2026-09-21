<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class ExistingDocblock
{
    /**
     * @var string
     */
    final protected $foo = 'bar';
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class ExistingDocblock
{
    /**
     * @var string
     * @final
     */
    protected $foo = 'bar';
}

?>
