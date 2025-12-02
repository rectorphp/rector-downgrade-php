<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class FixtureConstant
{
    public function run()
    {
        return hash(MHASH_XXH128, 'some-data-to-hash');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class FixtureConstant
{
    public function run()
    {
        return hash('md5', 'some-data-to-hash');
    }
}

?>
