<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector;
use Rector\DowngradePhp80\ValueObject\DowngradeAttributeToAnnotation;
use Rector\Tests\ConfigList;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->import(ConfigList::MAIN);
    $rectorConfig
        ->ruleWithConfiguration(DowngradeAttributeToAnnotationRector::class, [
            new DowngradeAttributeToAnnotation(
                'Symfony\Component\Routing\Annotation\Route',
                'Symfony\Component\Routing\Annotation\Route'
            ),
            new DowngradeAttributeToAnnotation('Symfony\Contracts\Service\Attribute\Required', 'required'),
            new DowngradeAttributeToAnnotation('Attribute', 'Attribute'),
        ]);
};
