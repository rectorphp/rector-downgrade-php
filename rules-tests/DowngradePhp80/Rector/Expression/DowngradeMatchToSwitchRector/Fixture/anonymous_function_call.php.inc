<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class AnonymousFunctionCallExecute
{
    public function execute($statusCode)
    {
        $output = function($value) {
            echo $value;
        };

        $output(match ($statusCode) {
            100, 200 => null,
            300 => 'not found',
            default => 'unknown status code',
        });
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class AnonymousFunctionCallExecute
{
    public function execute($statusCode)
    {
        $output = function($value) {
            echo $value;
        };

        switch ($statusCode) {
            case 100:
            case 200:
                $output(null);
                break;
            case 300:
                $output('not found');
                break;
            default:
                $output('unknown status code');
                break;
        }
    }
}

?>
