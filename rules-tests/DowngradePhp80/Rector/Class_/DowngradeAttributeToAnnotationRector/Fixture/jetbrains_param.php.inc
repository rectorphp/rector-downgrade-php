<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use Jetbrains\PhpStorm\Language;

final class SymfonyRoute
{
    public function someParam(
        #[Language('RegExp')]
        string $regex
    ) {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use Jetbrains\PhpStorm\Language;

final class SymfonyRoute
{
    public function someParam(
        string $regex
    ) {
    }
}

?>
