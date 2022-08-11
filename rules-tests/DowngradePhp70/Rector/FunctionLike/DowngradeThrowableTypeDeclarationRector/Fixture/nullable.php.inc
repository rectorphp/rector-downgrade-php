<?php

namespace Rector\Tests\DowngradePhp70\Rector\FunctionLike\DowngradeThrowableTypeDeclarationRector\Fixture;

class Fixture
{
    public function someFunction(?\Throwable $anything): ?\Throwable
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\FunctionLike\DowngradeThrowableTypeDeclarationRector\Fixture;

class Fixture
{
    /**
     * @param \Throwable|null $anything
     */
    public function someFunction($anything): ?\Throwable
    {
    }
}

?>
