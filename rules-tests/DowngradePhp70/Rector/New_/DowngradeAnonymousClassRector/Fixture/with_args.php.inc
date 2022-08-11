<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

class WithArgs
{
    public function run($arg1, $arg2)
    {
        return new class ($arg1, $arg2) {
            public function execute()
            {
            }
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

class WithArgs
{
    public function run($arg1, $arg2)
    {
        return new Anonymous__%s($arg1, $arg2);
    }
}
class Anonymous__%s
{
    public function execute()
    {
    }
}
