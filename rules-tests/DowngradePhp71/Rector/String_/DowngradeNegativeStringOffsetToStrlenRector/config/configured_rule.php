<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp71\Rector\String_\DowngradeNegativeStringOffsetToStrlenRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(DowngradeNegativeStringOffsetToStrlenRector::class);
};
