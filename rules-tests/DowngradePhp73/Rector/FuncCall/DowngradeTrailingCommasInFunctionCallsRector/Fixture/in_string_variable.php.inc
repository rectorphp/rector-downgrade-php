<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector\Fixture;

class InStringVariable
{
    public function run()
    {
        $this->setOnClick("[Zip ID: {$modelid}]  {$e->getMessage($modelId,)}",);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector\Fixture;

class InStringVariable
{
    public function run()
    {
        $this->setOnClick("[Zip ID: {$modelid}]  {$e->getMessage($modelId)}");
    }
}

?>
