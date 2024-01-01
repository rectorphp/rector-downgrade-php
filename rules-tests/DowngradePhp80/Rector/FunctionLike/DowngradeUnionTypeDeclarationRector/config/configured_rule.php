<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

use Rector\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector;
use Rector\ValueObject\PhpVersion;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->rule(DowngradeUnionTypeDeclarationRector::class);

    $rectorConfig->phpVersion(PhpVersion::PHP_80);
};
