<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

class Fixture
{
    public function run()
    {
        new Request()->withMethod('GET')->withUri('/hello-world');
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

class Fixture
{
    public function run()
    {
        (new Request())->withMethod('GET')->withUri('/hello-world');
    }
}

?>
