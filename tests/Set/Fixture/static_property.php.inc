<?php

namespace Rector\Tests\Set\Fixture;

final readonly class StaticProperty
{
    public static string $foo;
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class StaticProperty
{
    /**
     * @var string
     */
    public static $foo;
}

?>
