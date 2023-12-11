<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class ReturnTrue
{
    public function run(): true
    {
        return true;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class ReturnTrue
{
    /**
     * @return true
     */
    public function run(): bool
    {
        return true;
    }
}

?>