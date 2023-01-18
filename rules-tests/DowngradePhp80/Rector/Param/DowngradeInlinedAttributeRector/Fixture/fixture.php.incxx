<?php

namespace Rector\Tests\DowngradePhp80\Rector\Param\DowngradeInlinedAttributeRector\Fixture;

function grep(#[\JetBrains\PhpStorm\Language('RegExp')] string $pattern)
{}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Param\DowngradeInlinedAttributeRector\Fixture;

function grep(#[\JetBrains\PhpStorm\Language('RegExp')]
string $pattern)
{}

?>
