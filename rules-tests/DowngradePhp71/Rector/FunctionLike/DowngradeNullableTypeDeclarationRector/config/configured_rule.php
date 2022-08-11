<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\Core\ValueObject\PhpVersionFeature;
use Rector\DowngradePhp71\Rector\FunctionLike\DowngradeNullableTypeDeclarationRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../../../config/config.php');
    $rectorConfig->rule(DowngradeNullableTypeDeclarationRector::class);

    $rectorConfig->phpVersion(PhpVersionFeature::NULLABLE_TYPE - 1);
};
