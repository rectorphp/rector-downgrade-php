<?php
declare(strict_types=1);

namespace Rector\ValueObject;

final class ClassMethodWillChangeReturnType
{
    public function __construct(
        private readonly string $className,
        private readonly string $methodName,
        private readonly \PHPStan\Type\Type $returnType
    ) { }

    public function getClassName(): string
    {
        return $this->className;
    }

    public function getMethodName(): string
    {
        return $this->methodName;
    }

    public function getReturnType(): \PHPStan\Type\Type
    {
        return $this->returnType;
    }
}
