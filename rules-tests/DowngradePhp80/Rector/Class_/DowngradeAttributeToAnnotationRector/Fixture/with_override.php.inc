<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

final class WithOverride
{
    #[\Override]public function action()
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

final class WithOverride
{
    #[\Override]
    public function action()
    {
    }
}

?>
