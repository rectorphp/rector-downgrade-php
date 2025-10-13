<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class SkipAsFalsyArg
{
    public function run()
    {
        return $this->execute(substr('a', 2));
    }

    private function execute(false|string $value)
    {
        return $value;
    }
}
