<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp83\Rector\Class_\DowngradeReadonlyAnonymousClassRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeReadonlyAnonymousClassRector::class);
};
