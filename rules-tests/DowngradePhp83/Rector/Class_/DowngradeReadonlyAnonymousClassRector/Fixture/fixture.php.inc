<?php

namespace Rector\Tests\DowngradePhp83\Rector\Class_\DowngradeReadonlyAnonymousClassRector\Fixture;

final class Fixture
{
    public function run()
    {
        new readonly class {
            public string $foo = 'bar';
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp83\Rector\Class_\DowngradeReadonlyAnonymousClassRector\Fixture;

final class Fixture
{
    public function run()
    {
        new class {
            public readonly string $foo = 'bar';
        };
    }
}

?>