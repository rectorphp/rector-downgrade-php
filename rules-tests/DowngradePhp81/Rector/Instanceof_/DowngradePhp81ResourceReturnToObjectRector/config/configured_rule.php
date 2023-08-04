<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

use Rector\DowngradePhp81\Rector\Instanceof_\DowngradePhp81ResourceReturnToObjectRector;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig->rule(DowngradePhp81ResourceReturnToObjectRector::class);
};
