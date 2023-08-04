<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

use Rector\DowngradePhp72\Rector\FuncCall\DowngradeJsonDecodeNullAssociativeArgRector;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig->rule(DowngradeJsonDecodeNullAssociativeArgRector::class);
};
