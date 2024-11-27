<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class SkipAlreadyParentheses
{
    public function run()
    {
        (new Request())->withMethod('GET')->withUri('/hello-world');
    }
}
