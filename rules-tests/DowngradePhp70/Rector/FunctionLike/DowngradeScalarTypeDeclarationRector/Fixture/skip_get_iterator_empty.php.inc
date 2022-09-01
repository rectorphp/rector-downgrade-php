<?php

namespace Rector\Tests\DowngradePhp70\Rector\FunctionLike\DowngradeScalarTypeDeclarationRector\Fixture;
final class SkipGetIteratorEmpty
{
    public function getIterator(): \Iterator
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\FunctionLike\DowngradeScalarTypeDeclarationRector\Fixture;
final class SkipGetIteratorEmpty
{
    /**
     * @return \Iterator
     */
    public function getIterator()
    {
    }
}

?>
