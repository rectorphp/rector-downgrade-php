<?php

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector;
use Rector\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector;

return RectorConfig::configure()
    ->withRules([
        DowngradeNamedArgumentRector::class,
        DowngradeTrailingCommasInFunctionCallsRector::class,
    ]);
