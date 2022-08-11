<?php

namespace Rector\Tests\DowngradePhp70\Rector\ClassMethod\DowngradeSelfTypeDeclarationRector\Fixture;

class NullableType
{
    public function getSelfOrNull(): ?self
    {
        return $this;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\ClassMethod\DowngradeSelfTypeDeclarationRector\Fixture;

class NullableType
{
    public function getSelfOrNull(): ?static
    {
        return $this;
    }
}

?>
