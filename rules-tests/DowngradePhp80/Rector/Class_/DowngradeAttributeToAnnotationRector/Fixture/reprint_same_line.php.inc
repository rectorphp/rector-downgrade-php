<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use AllowDynamicProperties;

#[AllowDynamicProperties]class ReprintSameLine
{
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

use AllowDynamicProperties;

#[AllowDynamicProperties]
class ReprintSameLine
{
}

?>