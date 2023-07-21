<?php

namespace Rector\Tests\DowngradePhp71\Rector\FunctionLike\DowngradeIterablePseudoTypeDeclarationRector\Fixture;
final class ReturnIterable
{
    public function run(): iterable
    {
        // do something
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp71\Rector\FunctionLike\DowngradeIterablePseudoTypeDeclarationRector\Fixture;
final class ReturnIterable
{
    /**
     * @return iterable
     */
    public function run()
    {
        // do something
    }
}

?>
