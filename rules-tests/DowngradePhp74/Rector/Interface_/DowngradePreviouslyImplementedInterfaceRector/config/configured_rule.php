<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

use Rector\DowngradePhp74\Rector\Interface_\DowngradePreviouslyImplementedInterfaceRector;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig->rule(DowngradePreviouslyImplementedInterfaceRector::class);
};
