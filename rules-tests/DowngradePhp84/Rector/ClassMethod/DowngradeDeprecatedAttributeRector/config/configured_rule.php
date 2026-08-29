<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeDeprecatedAttributeRector::class);
};
