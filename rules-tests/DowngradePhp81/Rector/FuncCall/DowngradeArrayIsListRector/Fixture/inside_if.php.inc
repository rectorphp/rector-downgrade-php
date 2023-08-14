<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeArrayIsListRector\Fixture;

function insideIf($arguments)
{
    if (!\array_is_list($arguments)) {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeArrayIsListRector\Fixture;

function insideIf($arguments)
{
    $arrayIsListFunction = function (array $array) : bool {
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
    if (!$arrayIsListFunction($arguments)) {
    }
}

?>
