<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(DowngradeNamedArgumentRector::class);
};
