<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NewOnArrayDimFetch
{
    public function run()
    {
        $value = new \ArrayObject(['key' => 'value'])['key'];
        $nested = new \ArrayObject([])['a']['b'];
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class NewOnArrayDimFetch
{
    public function run()
    {
        $value = (new \ArrayObject(['key' => 'value']))['key'];
        $nested = (new \ArrayObject([]))['a']['b'];
    }
}

?>
