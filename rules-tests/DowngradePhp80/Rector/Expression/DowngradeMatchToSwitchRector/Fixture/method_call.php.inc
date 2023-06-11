<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class ClassFunctionCall
{
    public function output($value)
    {
        echo $value;
    }

    public function run($statusCode)
    {
        $this->output(match ($statusCode) {
            200, 300 => null,
            400 => 'not found',
            default => 'unknown status code',
        });
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class ClassFunctionCall
{
    public function output($value)
    {
        echo $value;
    }

    public function run($statusCode)
    {
        $this->output($statusCode === 200 || $statusCode === 300 ? null : ($statusCode === 400 ? 'not found' : 'unknown status code'));
    }
}

?>
