<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp82\Rector\MethodCall\DowngradeReflectionMethodHasPrototypeRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeReflectionMethodHasPrototypeRector::class);
};
