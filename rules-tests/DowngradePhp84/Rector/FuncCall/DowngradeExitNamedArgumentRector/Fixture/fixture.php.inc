<?php

namespace Rector\Tests\DowngradePhp84\Rector\FuncCall\DowngradeExitNamedArgumentRector\Fixture;

class Fixture
{
    public function run()
    {
        exit(status: 1);
        die(status: 'failure');
        \exit(status: getStatus());
        \die(status: getStatus());
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\FuncCall\DowngradeExitNamedArgumentRector\Fixture;

class Fixture
{
    public function run()
    {
        exit(1);
        die('failure');
        \exit(getStatus());
        \die(getStatus());
    }
}

?>
