<?php

namespace Rector\Tests\DowngradePhp70\Rector\New_\DowngradeAnonymousClassRector\Fixture;

class AnonymousFor_ClassExists
{
}
class ClassExists
{
    public function run()
    {
        return new class {
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

class AnonymousFor_ClassExists
{
}
class ClassExists
{
    public function run()
    {
        return new Anonymous__%s();
    }
}
class Anonymous__%s
{
    public function execute()
    {
    }
}
