<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class Nullsafe
{
    public function run()
    {
        new Request()?->withMethod('GET');
        $uri = new Request()?->uri;
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class Nullsafe
{
    public function run()
    {
        (new Request())?->withMethod('GET');
        $uri = (new Request())?->uri;
    }
}

?>
