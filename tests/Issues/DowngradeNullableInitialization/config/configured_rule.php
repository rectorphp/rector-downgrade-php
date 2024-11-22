<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector;
use Rector\DowngradePhp80\Rector\Class_\DowngradePropertyPromotionRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rules([
        DowngradeNewInInitializerRector::class,
        DowngradePropertyPromotionRector::class,
    ]);
};