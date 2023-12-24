<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

$output = function($value) {
    echo $value;
};

$output(match ($statusCode) {
    100, 200 => null,
    300 => 'not found',
    default => 'unknown status code',
});

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

$output = function($value) {
    echo $value;
};

$output((function () use ($statusCode) {
    switch ($statusCode) {
        case 100:
        case 200:
            return null;
        case 300:
            return 'not found';
        default:
            return 'unknown status code';
    }
})());

?>
