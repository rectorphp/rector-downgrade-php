<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp84\Rector\MethodCall\DowngradeNewMethodCallWithoutParenthesesRector\Fixture;

final class SkipAlreadyParenthesesOtherDereferences
{
    public function run()
    {
        $message = (new Regex('some-pattern'))->message;
        (new Request())?->withMethod('GET');
        $constant = (new Request())::METHOD_GET;
        $value = (new \ArrayObject(['key' => 'value']))['key'];
        $result = (new Invokable())();
        $callback = $this->callback;
        $items = $this->items['key'];
    }
}
