<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NestedNew
{
    public function run()
    {
        $value = new Outer(new Inner()->value)->run();
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NestedNew
{
    public function run()
    {
        $value = (new Outer((new Inner())->value))->run();
    }
}

?>
