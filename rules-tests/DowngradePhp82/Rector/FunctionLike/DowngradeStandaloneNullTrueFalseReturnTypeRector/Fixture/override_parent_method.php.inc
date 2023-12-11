<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\Source\ParentClass;

final class OverrideParentMethod extends ParentClass
{
    public function getSomeString(): null
    {
        return null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\Source\ParentClass;

final class OverrideParentMethod extends ParentClass
{
    /**
     * @return null
     */
    public function getSomeString(): ?string
    {
        return null;
    }
}

?>