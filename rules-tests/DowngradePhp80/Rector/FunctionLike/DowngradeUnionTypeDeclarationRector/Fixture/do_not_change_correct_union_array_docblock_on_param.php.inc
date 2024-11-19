<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

use PhpParser\Node;
use PhpParser\Node\Stmt;
final class DoNotChangeCorrectUnionArrayDocblockOnParam
{
    /**
     * @param int|string[] $data
     */
    public function run(int|array $data)
    {
    }

    /**
     * @param Node|null|Stmt[] $data
     */
    public function run2(Node|null|array $data)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

use PhpParser\Node;
use PhpParser\Node\Stmt;
final class DoNotChangeCorrectUnionArrayDocblockOnParam
{
    /**
     * @param int|string[] $data
     */
    public function run($data)
    {
    }

    /**
     * @param Node|null|Stmt[] $data
     */
    public function run2($data)
    {
    }
}

?>
