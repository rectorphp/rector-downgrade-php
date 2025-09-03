<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp83\Rector\Class_\DowngradeReadonlyAnonymousClassRector;
use Rector\ValueObject\PhpVersion;
use Rector\DowngradePhp83\Rector\ClassConst\DowngradeTypedClassConstRector;
use Rector\DowngradePhp83\Rector\ClassConstFetch\DowngradeDynamicClassConstFetchRector;
use Rector\DowngradePhp83\Rector\FuncCall\DowngradeJsonValidateRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->phpVersion(PhpVersion::PHP_82);
    $rectorConfig->rules([
        DowngradeTypedClassConstRector::class,
        DowngradeReadonlyAnonymousClassRector::class,
        DowngradeDynamicClassConstFetchRector::class,
        DowngradeJsonValidateRector::class,
    ]);
};
