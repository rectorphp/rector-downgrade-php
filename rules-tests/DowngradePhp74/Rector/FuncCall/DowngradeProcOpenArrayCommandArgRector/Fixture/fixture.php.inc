<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class Fixture
{
    function run(array|string $command)
    {
        $process = proc_open($command, $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class Fixture
{
    function run(array|string $command)
    {
        $process = proc_open(is_array($command) ? implode(' ', array_map('escapeshellarg', $command)) : $command, $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
