<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

return new class {
    public function execute()
    {
    }
};

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

return new Anonymous__%s();
class Anonymous__%s
{
    public function execute()
    {
    }
}
