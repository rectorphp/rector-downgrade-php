<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Source\SomeAttributes;

final class Anything extends SomeAttributes
{
    public function __construct()
    {
        parent::__construct(
            tags: ['some_items']
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Source\SomeAttributes;

final class Anything extends SomeAttributes
{
    public function __construct()
    {
        parent::__construct(
            ['some_items']
        );
    }
}

?>
