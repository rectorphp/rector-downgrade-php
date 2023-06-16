<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Source\Foo;

$name = "bar";
$new_value = 42;

$foo = new Foo();

$func = fn() => ($foo->{$name} = $new_value);

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Source\Foo;

$name = "bar";
$new_value = 42;

$foo = new Foo();

$func = function () use ($foo, $name, $new_value) {
    return $foo->{$name} = $new_value;
};

?>
