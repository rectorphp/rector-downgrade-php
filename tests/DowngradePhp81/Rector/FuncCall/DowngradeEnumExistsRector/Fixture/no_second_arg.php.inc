<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeEnumExistsRector\Fixture;

enum_exists('SomeEnum');

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeEnumExistsRector\Fixture;

$enumExists = function (string $enum, bool $autoload = true) : bool {
    if (function_exists('enum_exists')) {
        return enum_exists($enum, $autoload);
    }
    return $autoload && class_exists($enum) && false;
};
$enumExists('SomeEnum');

?>
