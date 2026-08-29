<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class SkipOtherAttribute
{
    #[\Override]
    public function someMethod(): void
    {
    }
}
