<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp54\Rector\Array_\ShortArrayToLongArrayRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(ShortArrayToLongArrayRector::class);
};
