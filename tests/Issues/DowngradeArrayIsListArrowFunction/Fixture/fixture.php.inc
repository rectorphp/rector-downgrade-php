<?php

namespace Rector\Tests\Issues\DowngradeArrayIsListArrowFunction\Fixture;

class Fixture
{
    public function run($items)
    {
        return array_map(
            fn($item) => is_array($item) && !array_is_list($item)? (object) $this->convertToObject($item) : ($item),
            $items
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeArrayIsListArrowFunction\Fixture;

class Fixture
{
    public function run($items)
    {
        $arrayIsListFunction = function (array $array): bool {
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
        return array_map(
            function ($item) use ($arrayIsListFunction) {
                return is_array($item) && !$arrayIsListFunction($item)? (object) $this->convertToObject($item) : ($item);
            },
            $items
        );
    }
}

?>
