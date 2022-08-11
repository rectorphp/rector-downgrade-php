<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\Core\ValueObject\PhpVersionFeature;
use Rector\DowngradePhp72\Rector\FunctionLike\DowngradeObjectTypeDeclarationRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(DowngradeObjectTypeDeclarationRector::class);

    $rectorConfig->phpVersion(PhpVersionFeature::NULLABLE_TYPE - 1);
};
