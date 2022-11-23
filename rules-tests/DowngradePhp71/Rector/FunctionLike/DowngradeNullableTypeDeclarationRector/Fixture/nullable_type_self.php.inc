<?php

namespace Rector\Tests\DowngradePhp71\Rector\FunctionLike\DowngradeNullableTypeDeclarationRector\Fixture;

class NullableTypeSelf
{
    public function getSelfOrNull(): ?self
    {
        return $this;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\FunctionLike\DowngradeNullableTypeDeclarationRector\Fixture;

class NullableTypeSelf
{
    /**
     * @return $this|null
     */
    public function getSelfOrNull()
    {
        return $this;
    }
}

?>
