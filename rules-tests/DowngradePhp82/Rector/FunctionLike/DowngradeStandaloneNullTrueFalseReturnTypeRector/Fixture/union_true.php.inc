<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class UnionTrue
{
    public function run(): null|true
    {
        return rand(0, 1) ? true : null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class UnionTrue
{
    /**
     * @return null|true
     */
    public function run(): null|bool
    {
        return rand(0, 1) ? true : null;
    }
}

?>