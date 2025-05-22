<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp83\Rector\ClassConstFetch\DowngradeDynamicClassConstFetchRector\Fixture;

class Fixture
{
    public const string FOO = 'foo';

    public function run()
    {
        $someValue = 'foo';
        Fixture::{$someValue};
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp83\Rector\ClassConstFetch\DowngradeDynamicClassConstFetchRector\Fixture;

class Fixture
{
    public const string FOO = 'foo';

    public function run()
    {
        $someValue = 'foo';
        constant(Fixture::class . '::' . $someValue);
    }
}

?>
