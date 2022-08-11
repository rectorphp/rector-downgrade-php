<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;

return static function (RectorConfig $rectorConfig): void {
    $services = $rectorConfig->services();

    $services->defaults()
        ->public()
        ->autowire()
        ->autoconfigure();

    $services->load('Rector\\', __DIR__ . '/../rules')
        ->exclude([
<<<<<<< HEAD
=======
            __DIR__ . '/../src/ValueObject'
        ]);

    $services->load('Rector\\', __DIR__ . '/../rules')
        ->exclude([
>>>>>>> move PhpDocFromTypeDeclarationDecorator from core here, as only used in downgrades; move rules to rules
            __DIR__ . '/../rules/Downgrade*/Rector',
            __DIR__ . '/../rules/*/ValueObject',
            __DIR__ . '/../rules/DowngradePhp80/Reflection/SimplePhpParameterReflection.php',
        ]);
};
