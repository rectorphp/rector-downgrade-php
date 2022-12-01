<?php

namespace Rector\Tests\DowngradePhp80\Rector\ClassMethod\RemoveReturnTypeDeclarationFromCloneRector\Fixture;

final class SomeClass
{
    public function __clone(): void
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\ClassMethod\RemoveReturnTypeDeclarationFromCloneRector\Fixture;

final class SomeClass
{
    public function __clone()
    {
    }
}

?>
