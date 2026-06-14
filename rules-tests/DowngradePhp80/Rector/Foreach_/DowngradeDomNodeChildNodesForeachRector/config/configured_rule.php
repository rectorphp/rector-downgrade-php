<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeDomNodeChildNodesForeachRector::class);
};
