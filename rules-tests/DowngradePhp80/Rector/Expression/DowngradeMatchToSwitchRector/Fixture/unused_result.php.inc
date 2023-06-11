<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class UnusedResult
{
    public function run($statusCode)
    {
        match ($statusCode) {
            200, 300 => null,
            400 => (function() { echo 'not found'; })(),
            default => 'unknown status code',
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class UnusedResult
{
    public function run($statusCode)
    {
        $statusCode === 200 || $statusCode === 300 ? null : ($statusCode === 400 ? (function() { echo 'not found'; })() : 'unknown status code');
    }
}

?>
