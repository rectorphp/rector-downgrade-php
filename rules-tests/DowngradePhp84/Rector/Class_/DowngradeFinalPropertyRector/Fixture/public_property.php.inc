<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class PublicProperty
{
    final public string $foo = 'bar';
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\Class_\DowngradeFinalPropertyRector\Fixture;

class PublicProperty
{
    /**
     * @final
     */
    public string $foo = 'bar';
}

?>
