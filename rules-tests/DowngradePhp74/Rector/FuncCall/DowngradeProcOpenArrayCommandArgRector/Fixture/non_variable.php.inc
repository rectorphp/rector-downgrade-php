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
        $process = proc_open(is_array(['ls', '-l']) ? implode(' ', ['ls', '-l']) : ['ls', '-l'], $descriptorspec, $pipes, null, null, ['suppress_errors' => true]);
    }
}

?>
