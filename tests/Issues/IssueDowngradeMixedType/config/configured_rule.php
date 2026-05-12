<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp74\Rector\Property\DowngradeTypedPropertyRector;
use Rector\DowngradePhp80\Rector\FunctionLike\DowngradeMixedTypeDeclarationRector;
use Rector\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector;
use Rector\DowngradePhp80\ValueObject\DowngradeAttributeToAnnotation;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->importNames();
    $rectorConfig->rule(DowngradeTypedPropertyRector::class);
    $rectorConfig->rule(DowngradeMixedTypeDeclarationRector::class);

    $rectorConfig
        ->ruleWithConfiguration(DowngradeAttributeToAnnotationRector::class, [
            // Symfony
            new DowngradeAttributeToAnnotation('Symfony\Contracts\Service\Attribute\Required', 'required'),
            // Nette
            new DowngradeAttributeToAnnotation('Nette\DI\Attributes\Inject', 'inject'),
            // Jetbrains\PhpStorm\Language under nette/utils
            new DowngradeAttributeToAnnotation('Jetbrains\PhpStorm\Language', 'language'),
        ]);
};
