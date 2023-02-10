<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\Handler;
use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\ResponseInterface;
use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\TempResponse;

/**
 * @extends Handler<TempResponse>
 */
final class SkipSameReturnType extends Handler
{
    protected function set(): ResponseInterface {
        return new TempResponse();
    }
}
