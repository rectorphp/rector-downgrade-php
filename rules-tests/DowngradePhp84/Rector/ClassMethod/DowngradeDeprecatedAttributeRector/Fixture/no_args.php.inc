<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class NoArgs
{
    #[\Deprecated]
    public function someMethod(): void
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class NoArgs
{
    /**
     * @deprecated
     */
    public function someMethod(): void
    {
    }
}

?>
