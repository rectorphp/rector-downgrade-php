<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class AnonymousFunctionCall
{
    public function run($statusCode)
    {
        $output = function($value) {
            echo $value;
        };

        $output(match ($statusCode) {
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

class AnonymousFunctionCall
{
    public function run($statusCode)
    {
        $output = function($value) {
            echo $value;
        };

        $output($statusCode === 200 || $statusCode === 300 ? null : ($statusCode === 400 ? 'not found' : 'unknown status code'));
    }
}

?>
