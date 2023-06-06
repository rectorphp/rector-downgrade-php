<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeStripTagsCallWithArrayRector\Fixture;

final class Consts
{
    const SOME_CONST = ['a', 'p'];

    public function run($string)
    {
        // Consts: if array, change to string
        strip_tags($string, self::SOME_CONST);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeStripTagsCallWithArrayRector\Fixture;

final class Consts
{
    const SOME_CONST = ['a', 'p'];

    public function run($string)
    {
        // Consts: if array, change to string
        strip_tags($string, self::SOME_CONST !== null && is_array(self::SOME_CONST) ? '<' . implode('><', self::SOME_CONST) . '>' : self::SOME_CONST);
    }
}

?>
