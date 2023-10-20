<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class Fixture
{
    public function run()
    {
        return hash(algo: 'xxh128', data: 'some-data-to-hash');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class Fixture
{
    public function run()
    {
        return hash(algo: 'md5', data: 'some-data-to-hash');
    }
}

?>
