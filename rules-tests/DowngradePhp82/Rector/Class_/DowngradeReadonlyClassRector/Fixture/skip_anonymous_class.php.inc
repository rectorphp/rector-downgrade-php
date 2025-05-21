<?php

namespace Rector\Tests\DowngradePhp82\Rector\Class_\DowngradeReadonlyClassRector\Fixture;

final class SkipAnonymousClass
{
    public function run()
    {
        new readonly class {
            public string $foo = 'bar';
        };
    }
}
