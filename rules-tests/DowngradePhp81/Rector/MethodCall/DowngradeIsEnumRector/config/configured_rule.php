<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp81\Rector\MethodCall\DowngradeIsEnumRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeIsEnumRector::class);
};
