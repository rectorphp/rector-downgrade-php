<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector;
use Rector\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rules([DowngradeThrowExprRector::class, DowngradeNullsafeToTernaryOperatorRector::class]);
};
