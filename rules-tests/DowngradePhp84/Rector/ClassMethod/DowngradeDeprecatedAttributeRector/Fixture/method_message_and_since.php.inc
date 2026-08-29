<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class MethodMessageAndSince
{
    #[\Deprecated(message: 'use someOtherMethod() instead', since: '1.5')]
    public function someMethod(): void
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class MethodMessageAndSince
{
    /**
     * @deprecated 1.5 use someOtherMethod() instead
     */
    public function someMethod(): void
    {
    }
}

?>
