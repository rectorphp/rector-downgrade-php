<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Fixture;

use Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Source\SomeParentVoid;

class WithParentIsVoid extends SomeParentVoid
{
    public function run(): never
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Fixture;

use Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Source\SomeParentVoid;

class WithParentIsVoid extends SomeParentVoid
{
    /**
     * @return never
     */
    public function run(): void
    {
    }
}

?>
