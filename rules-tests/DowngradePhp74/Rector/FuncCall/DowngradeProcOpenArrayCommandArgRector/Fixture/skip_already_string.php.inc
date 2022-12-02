<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class SkipAlreadyString
{
    function run(string $command)
    {
        $process = proc_open($command, $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}
