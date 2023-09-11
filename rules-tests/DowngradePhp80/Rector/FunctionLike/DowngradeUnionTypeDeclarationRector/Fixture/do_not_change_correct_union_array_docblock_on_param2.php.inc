<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

use PhpParser\Node;

final class DoNotChangeCorrectUnionArrayDocblockOnParam2
{
    /**
     * @param Node|Node[] $node
     */
    function execute(Node | array $node): void
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector\Fixture;

use PhpParser\Node;

final class DoNotChangeCorrectUnionArrayDocblockOnParam2
{
    /**
     * @param Node|Node[] $node
     */
    function execute($node): void
    {
    }
}

?>
