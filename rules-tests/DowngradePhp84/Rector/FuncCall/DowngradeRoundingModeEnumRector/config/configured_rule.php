<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp84\Rector\FuncCall\DowngradeRoundingModeEnumRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeRoundingModeEnumRector::class);
};
