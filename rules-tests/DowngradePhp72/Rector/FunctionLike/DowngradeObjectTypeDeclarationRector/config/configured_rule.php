<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

use Rector\DowngradePhp72\Rector\FunctionLike\DowngradeObjectTypeDeclarationRector;
use Rector\ValueObject\PhpVersionFeature;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeObjectTypeDeclarationRector::class);

    $rectorConfig->phpVersion(PhpVersionFeature::NULLABLE_TYPE - 1);
};
