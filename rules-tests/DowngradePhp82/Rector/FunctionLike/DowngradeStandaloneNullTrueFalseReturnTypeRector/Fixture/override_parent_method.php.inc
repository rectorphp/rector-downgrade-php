<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\ParentClass;

final class OverrideParentMethod extends ParentClass
{
    public function run(): null
    {
        return null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\ParentClass;

final class OverrideParentMethod extends ParentClass
{
    /**
     * @return null
     */
    public function run(): ?string
    {
        return null;
    }
}

?>