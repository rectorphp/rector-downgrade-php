<?php

declare(strict_types=1);

use Rector\CodingStyle\Rector\String_\UseClassKeywordForClassNameResolutionRector;
use Rector\Config\RectorConfig;
use Rector\Php55\Rector\String_\StringClassNameToClassConstantRector;
use Rector\PHPUnit\Set\PHPUnitSetList;

return RectorConfig::configure()
    ->withImportNames(removeUnusedImports: true)
    ->withPhpSets(php82: true)
    ->withSets([
        PHPUnitSetList::PHPUNIT_100,
        PHPUnitSetList::PHPUNIT_CODE_QUALITY,
    ])
    ->withPreparedSets(
        codeQuality: true,
        codingStyle: true,
        deadCode: true,
        privatization: true,
        naming: true,
        typeDeclarations: true,
        earlyReturn: true,
        rectorPreset: true
    )->withPaths([
        __DIR__ . '/src',
        __DIR__ . '/rules',
        __DIR__ . '/tests',
        __DIR__ . '/rules-tests',
        __DIR__ . '/config',
    ])
    ->withRootFiles()
    ->withSkip([
        StringClassNameToClassConstantRector::class,

        UseClassKeywordForClassNameResolutionRector::class => [
            // not useful short class cases, possibly skip in the rule
            __DIR__ . '/rules/DowngradePhp80/Rector/MethodCall/DowngradeReflectionClassGetConstantsFilterRector.php',
            __DIR__ . '/rules/DowngradePhp81/Rector/FuncCall/DowngradeFirstClassCallableSyntaxRector.php',
        ],

        // test paths
        '**/Fixture/*',
        '**/Source/*',
        '**/Expected/*',
    ]);
