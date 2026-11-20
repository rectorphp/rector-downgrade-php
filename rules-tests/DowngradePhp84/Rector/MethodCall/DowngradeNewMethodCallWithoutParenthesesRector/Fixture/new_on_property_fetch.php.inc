<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NewOnPropertyFetch
{
    public function run()
    {
        $message = new Regex('some-pattern')->message;
        $nested = new Request()->uri->path;
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NewOnPropertyFetch
{
    public function run()
    {
        $message = (new Regex('some-pattern'))->message;
        $nested = (new Request())->uri->path;
    }
}

?>
