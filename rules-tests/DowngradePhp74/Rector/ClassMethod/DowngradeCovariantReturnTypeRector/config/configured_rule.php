<?php

declare(strict_types=1);
use Rector\Core\ValueObject\PhpVersionFeature;

use Rector\Config\RectorConfig;

use Rector\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig->rule(DowngradeCovariantReturnTypeRector::class);

    $rectorConfig->phpVersion(PhpVersionFeature::COVARIANT_RETURN);
};
