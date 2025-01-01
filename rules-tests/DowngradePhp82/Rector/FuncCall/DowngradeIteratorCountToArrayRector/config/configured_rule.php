<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeIteratorCountToArrayRector::class);
};
