<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeArrayIsListRector\Fixture;

$arrayIsListFunction = false;
array_is_list([1 => 'apple', 'orange']);

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeArrayIsListRector\Fixture;

$arrayIsListFunction = false;
$arrayIsListFunction2 = function (array $array) : bool {
    if (function_exists('array_is_list')) {
        return array_is_list($array);
    }
    if ($array === []) {
        return true;
    }
    $current_key = 0;
    foreach ($array as $key => $noop) {
        if ($key !== $current_key) {
            return false;
        }
        ++$current_key;
    }
    return true;
};
$arrayIsListFunction2([1 => 'apple', 'orange']);

?>
