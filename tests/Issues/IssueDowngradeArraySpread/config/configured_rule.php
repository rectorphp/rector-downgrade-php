<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector;
use Rector\DowngradePhp81\Rector\Array_\DowngradeArraySpreadStringKeyRector;
use Rector\ValueObject\PhpVersion;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rules([DowngradeArraySpreadStringKeyRector::class, DowngradeArraySpreadRector::class]);

    $rectorConfig->phpVersion(PhpVersion::PHP_81);
};
