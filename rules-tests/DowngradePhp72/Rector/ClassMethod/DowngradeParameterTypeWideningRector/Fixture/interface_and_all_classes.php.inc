<?php

namespace Rector\Tests\DowngradePhp72\Rector\ClassMethod\DowngradeParameterTypeWideningRector\Fixture;

interface SomeContainerInterface
{
    public function has(string $id);
}

final class SomeContainerBuilder implements SomeContainerInterface
{
    public function has(string $id)
    {
    }
}

class SomeUniqueContainer implements SomeContainerInterface
{
    public function has(string $id)
    {
    }
}

?>