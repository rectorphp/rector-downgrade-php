<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipNewArgFalsy
{
    public function __construct(false|string $value)
    {
    }

    public function run()
    {
        new self(substr('a', 2));
    }
}
