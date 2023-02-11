<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source;

/**
 * @template T of ResponseInterface
 */
abstract class Handler
{
    /**
     * @return T
     */
    abstract protected function set(): ResponseInterface;
}
