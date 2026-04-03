<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class InArrayDimFetch
{
    public function run($c, $n, $v)
    {
        $properties[match ($c) {
            'Error' => 'TypeError',
            'Exception' => 'ErrorException',
            default => $c,
        }][$n] = $v;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class InArrayDimFetch
{
    public function run($c, $n, $v)
    {
        switch ($c) {
            case 'Error':
                $match = 'TypeError';
                break;
            case 'Exception':
                $match = 'ErrorException';
                break;
            default:
                $match = $c;
                break;
        }
        $properties[$match][$n] = $v;
    }
}

?>
