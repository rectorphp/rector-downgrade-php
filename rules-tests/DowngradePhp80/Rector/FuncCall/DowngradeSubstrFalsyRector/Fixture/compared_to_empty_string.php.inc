<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class ComparedToEmptyString
{
    public function run(string $name)
    {
        return substr($name, 2) === '';
    }
    
    public function run2(string $name)
    {
        return substr($name, 2) !== '';
    }
    
    public function run3(string $name)
    {
        return substr($name, 2) == '';
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class ComparedToEmptyString
{
    public function run(string $name)
    {
        return (string) substr($name, 2) === '';
    }
    
    public function run2(string $name)
    {
        return (string) substr($name, 2) !== '';
    }
    
    public function run3(string $name)
    {
        return (string) substr($name, 2) == '';
    }
}

?>
