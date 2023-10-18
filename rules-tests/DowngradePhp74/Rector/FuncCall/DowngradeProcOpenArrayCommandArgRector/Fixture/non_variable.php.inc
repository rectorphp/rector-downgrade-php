<?php

namespace Rector\Tests\DowngradePhp74\Rector\FuncCall\DowngradeProcOpenArrayCommandArgRector\Fixture;

class NonVariable
{
    function run()
    {
        $process = proc_open(['rm', '-r', 'my dir'], $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
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
        $process = proc_open(is_array(['rm', '-r', 'my dir']) ? implode(' ', array_map('escapeshellarg', ['rm', '-r', 'my dir'])) : ['rm', '-r', 'my dir'], $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
