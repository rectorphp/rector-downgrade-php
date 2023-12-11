<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

function run(): null
{
    return null;
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

/**
 * @return null
 */
function run(): mixed
{
    return null;
}

?>