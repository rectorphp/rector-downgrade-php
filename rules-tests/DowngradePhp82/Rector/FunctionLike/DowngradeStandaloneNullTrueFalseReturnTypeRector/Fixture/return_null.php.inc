<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class ReturnNull
{
    public function run(): null
    {
        return null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeStandaloneNullTrueFalseReturnTypeRector\Fixture;

final class ReturnNull
{
    public function run(): mixed
    {
        return null;
    }
}

?>