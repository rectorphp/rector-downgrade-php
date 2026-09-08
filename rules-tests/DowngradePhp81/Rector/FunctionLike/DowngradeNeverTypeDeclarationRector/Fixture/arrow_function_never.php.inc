<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Fixture;

$callable = fn (): never => throw new \RuntimeException();

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNeverTypeDeclarationRector\Fixture;

$callable = fn () => throw new \RuntimeException();

?>
