<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class ByVariableString
{
    public function run(string $name)
    {
        return substr($name, 2);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

class ByVariableString
{
    public function run(string $name)
    {
        return (string) substr($name, 2);
    }
}

?>
