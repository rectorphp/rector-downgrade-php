<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp70\Rector\ClassMethod\DowngradeParentTypeDeclarationRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(DowngradeParentTypeDeclarationRector::class);
};
