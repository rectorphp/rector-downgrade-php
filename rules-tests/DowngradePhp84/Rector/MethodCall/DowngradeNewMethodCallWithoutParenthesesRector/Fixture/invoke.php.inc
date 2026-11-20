<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class Invoke
{
    public function run()
    {
        $result = new Invokable()();
        $withArgs = new Invokable(1)(2, 3);
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class Invoke
{
    public function run()
    {
        $result = (new Invokable())();
        $withArgs = (new Invokable(1))(2, 3);
    }
}

?>
