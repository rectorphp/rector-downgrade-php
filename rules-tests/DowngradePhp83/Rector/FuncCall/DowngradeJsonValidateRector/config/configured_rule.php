<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp83\Rector\FuncCall\DowngradeJsonValidateRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeJsonValidateRector::class);
};
