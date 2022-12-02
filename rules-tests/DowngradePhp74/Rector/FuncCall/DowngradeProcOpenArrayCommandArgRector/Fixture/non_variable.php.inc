<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class NonVariable
{
    function run()
    {
        $process = proc_open(['ls', '-l'], $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class NonVariable
{
    function run()
    {
        $command = ['ls', '-l'];
        if (is_array($command)) {
            $command = implode(' ', $command);
        }
        $process = proc_open($command, $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
