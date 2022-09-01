<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;
final class ParamNullableUnion
{
    public function run(int|null $value)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;
final class ParamNullableUnion
{
    public function run(?int $value)
    {
    }
}

?>
