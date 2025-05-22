<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp83\Rector\ClassConstFetch\DowngradeDynamicClassConstFetchRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeDynamicClassConstFetchRector::class);
};
