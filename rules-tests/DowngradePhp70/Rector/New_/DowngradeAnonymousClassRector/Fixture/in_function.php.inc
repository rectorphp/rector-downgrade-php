<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

function inFunction()
{
    return new class {
            public function execute()
            {
            }
    };
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

function inFunction()
{
    return new Anonymous__%s();
}
class Anonymous__%s
{
    public function execute()
    {
    }
}
