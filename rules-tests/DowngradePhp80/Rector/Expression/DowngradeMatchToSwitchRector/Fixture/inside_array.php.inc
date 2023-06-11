<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class InsideArray
{
    public function run($statusCode)
    {
        return [
            match ($statusCode) {
                200, 300 => null,
                400 => 'not found',
                default => 'unknown status code',
            },
        ];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class InsideArray
{
    public function run($statusCode)
    {
        return [
            $statusCode === 200 || $statusCode === 300 ? null : ($statusCode === 400 ? 'not found' : 'unknown status code'),
        ];
    }
}

?>
