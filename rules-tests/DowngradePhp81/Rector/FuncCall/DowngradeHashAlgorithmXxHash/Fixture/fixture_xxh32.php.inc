<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class FixtureXxh32
{
    public function run()
    {
        $value = hash('xxh32', 'some-data-to-hash');

        $value = hash('xxh64', 'some-data-to-hash');

        $value = hash('xxh128', 'some-data-to-hash');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

final class FixtureXxh32
{
    public function run()
    {
        $value = hash('md5', 'some-data-to-hash');

        $value = hash('md5', 'some-data-to-hash');

        $value = hash('md5', 'some-data-to-hash');
    }
}

?>
