<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\ArrayDimFetch\DowngradeDereferenceableOperationRector;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig->rule(DowngradeDereferenceableOperationRector::class);
};
