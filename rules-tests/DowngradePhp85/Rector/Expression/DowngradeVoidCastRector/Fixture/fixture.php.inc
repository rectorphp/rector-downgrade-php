<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\Expression\DowngradeVoidCastRector\Fixture;

final class Fixture
{
    #[\NoDiscard]
    function foo(): string {
        return 'bar';
    }

    public function run()
    {
        (void) $this->foo();
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\Expression\DowngradeVoidCastRector\Fixture;

final class Fixture
{
    #[\NoDiscard]
    function foo(): string {
        return 'bar';
    }

    public function run()
    {
        $_void = $this->foo();
    }
}

?>
