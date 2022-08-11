<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class NullableTrioDocblock
{
    public function run($value): int|null|string
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class NullableTrioDocblock
{
    /**
     * @return int|null|string
     */
    public function run($value)
    {
    }
}

?>
