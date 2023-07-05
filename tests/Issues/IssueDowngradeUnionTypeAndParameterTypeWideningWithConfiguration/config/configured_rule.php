<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\FunctionLike\DowngradeUnionTypeDeclarationRector;
use Rector\DowngradePhp72\Rector\ClassMethod\DowngradeParameterTypeWideningRector;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(__DIR__ . '/../../../../config/config.php');

    $rectorConfig->rule(DowngradeUnionTypeDeclarationRector::class);
    $rectorConfig->rule(DowngradeParameterTypeWideningRector::class);
    
    $rectorConfig
        ->ruleWithConfiguration(DowngradeParameterTypeWideningRector::class, [
            // WithInstanceManagerServiceTrait::class => ['getInstanceManager'],
        ]);
};
