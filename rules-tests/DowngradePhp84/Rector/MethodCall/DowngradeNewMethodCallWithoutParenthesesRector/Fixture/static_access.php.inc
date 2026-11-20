<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class StaticAccess
{
    public function run()
    {
        new Request()::create();
        $constant = new Request()::METHOD_GET;
        $property = new Request()::$defaultMethod;
        $className = new Request()::class;
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class StaticAccess
{
    public function run()
    {
        (new Request())::create();
        $constant = (new Request())::METHOD_GET;
        $property = (new Request())::$defaultMethod;
        $className = (new Request())::class;
    }
}

?>
