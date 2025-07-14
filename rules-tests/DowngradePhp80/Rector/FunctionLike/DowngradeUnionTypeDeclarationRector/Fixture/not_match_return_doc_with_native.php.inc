<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class NotMatchReturnDocWithNative
{
    /**
     * @return \stdClass[]|null
     */
    public function run($value): int|null|array
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

final class NotMatchReturnDocWithNative
{
    /**
     * @return \stdClass[]|null
     */
    public function run($value)
    {
    }
}

?>
