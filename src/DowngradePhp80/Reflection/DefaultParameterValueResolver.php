<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Reflection;

use PhpParser\BuilderHelpers;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\ConstFetch;
use PhpParser\Node\Name;
use PHPStan\Reflection\ParameterReflection;
use PHPStan\Type\Constant\ConstantArrayType;
use PHPStan\Type\Constant\ConstantBooleanType;
use PHPStan\Type\ConstantType;
use PHPStan\Type\Type;
use PHPStan\Type\VerbosityLevel;
use Rector\Core\Exception\ShouldNotHappenException;

final class DefaultParameterValueResolver
{
    public function resolveFromParameterReflection(ParameterReflection $parameterReflection): Expr | null
    {
        $defaultValue = $parameterReflection->getDefaultValue();
        if (! $defaultValue instanceof Type) {
            return null;
        }

        if (! $defaultValue instanceof ConstantType) {
            throw new ShouldNotHappenException();
        }

        return $this->resolveValueFromType($defaultValue);
    }

    private function resolveValueFromType(ConstantType $constantType): ConstFetch | Expr
    {
        if ($constantType instanceof ConstantBooleanType) {
            return $this->resolveConstantBooleanType($constantType);
        }

        if ($constantType instanceof ConstantArrayType) {
            $values = [];
            foreach ($constantType->getValueTypes() as $valueType) {
                if (! $valueType instanceof ConstantType) {
                    throw new ShouldNotHappenException();
                }

                $values[] = $this->resolveValueFromType($valueType);
            }

            return BuilderHelpers::normalizeValue($values);
        }

        return BuilderHelpers::normalizeValue($constantType->getValue());
    }

    private function resolveConstantBooleanType(ConstantBooleanType $constantBooleanType): ConstFetch
    {
        $value = $constantBooleanType->describe(VerbosityLevel::value());
        return new ConstFetch(new Name($value));
    }
}
