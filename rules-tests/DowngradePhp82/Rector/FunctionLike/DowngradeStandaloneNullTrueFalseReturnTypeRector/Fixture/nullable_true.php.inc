<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class NullableTrue
{
    public function run(): ?true
    {
        return rand(0, 1) ? true : null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class NullableTrue
{
    /**
     * @return true|null
     */
    public function run(): ?bool
    {
        return rand(0, 1) ? true : null;
    }
}

?>
