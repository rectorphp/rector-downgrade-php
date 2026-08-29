<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class ClassConstDeprecated
{
    #[\Deprecated('use NEW_VALUE instead')]
    public const OLD_VALUE = 1;
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class ClassConstDeprecated
{
    /**
     * @deprecated use NEW_VALUE instead
     */
    public const OLD_VALUE = 1;
}

?>
