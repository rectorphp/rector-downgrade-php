<?php

namespace Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\Fixture;

class Fixture
{
    public function run()
    {
        return hash(data: 'some-data-to-hash', algo: 'xxh128');
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
        return hash(data: 'some-data-to-hash', algo: 'md5');
    }
}

?>
