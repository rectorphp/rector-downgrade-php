<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class MatchReturnDocWithNative
{
    /**
     * @return \stdClass[]|null|int
     */
    public function run($value): int|null|array
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class MatchReturnDocWithNative
{
    /**
     * @return \stdClass[]|null|int
     */
    public function run($value)
    {
    }
}

?>
