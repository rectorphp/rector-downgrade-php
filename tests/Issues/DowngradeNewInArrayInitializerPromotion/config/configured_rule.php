<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp74\Rector\Property\DowngradeTypedPropertyRector;
use Rector\DowngradePhp80\Rector\Class_\DowngradePropertyPromotionRector;
use Rector\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rules([
        DowngradeNewInInitializerRector::class,
        DowngradePropertyPromotionRector::class,
        DowngradeTypedPropertyRector::class,
    ]);
};
