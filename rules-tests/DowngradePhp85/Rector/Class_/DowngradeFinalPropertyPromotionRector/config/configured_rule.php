<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeFinalPropertyPromotionRector::class);
};
