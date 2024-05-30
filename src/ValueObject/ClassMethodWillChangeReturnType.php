<?php

declare(strict_types=1);

namespace Rector\ValueObject;

final readonly class ClassMethodWillChangeReturnType
{
    public function __construct(
        private string $className,
        private string $methodName,
    ) {
    }

    public function getClassName(): string
    {
        return $this->className;
    }

    public function getMethodName(): string
    {
        return $this->methodName;
    }
}
