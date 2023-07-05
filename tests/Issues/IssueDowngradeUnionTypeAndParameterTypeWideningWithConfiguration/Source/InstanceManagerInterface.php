<?php

declare(strict_types=1);

namespace Rector\Tests\Issues\IssueDowngradeUnionTypeAndParameterTypeWideningWithConfiguration\Source;

interface InstanceManagerInterface
{
    public function getInstance(string $class): object;
    public function hasInstance(string $class): bool;
}
