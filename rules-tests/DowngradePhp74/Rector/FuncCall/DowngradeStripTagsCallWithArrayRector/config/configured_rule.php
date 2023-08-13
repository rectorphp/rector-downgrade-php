<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp74\Rector\FuncCall\DowngradeStripTagsCallWithArrayRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeStripTagsCallWithArrayRector::class);
};
