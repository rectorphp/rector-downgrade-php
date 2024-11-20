<?php

declare(strict_types=1);

namespace Rector\DowngradePhp74\Rector\ClassMethod;

use PhpParser\Node;
use PhpParser\Node\NullableType;
use PhpParser\Node\Param;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Function_;
use PhpParser\Node\UnionType;
use PHPStan\Reflection\ClassReflection;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfoFactory;
use Rector\BetterPhpDocParser\PhpDocManipulator\PhpDocTypeChanger;
use Rector\NodeAnalyzer\ParamAnalyzer;
use Rector\Rector\AbstractRector;
use Rector\Reflection\ReflectionResolver;
use Rector\StaticTypeMapper\StaticTypeMapper;
use Rector\ValueObject\MethodName;
use ReflectionMethod;
use ReflectionNamedType;
use ReflectionParameter;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://www.php.net/manual/en/language.oop5.variance.php#language.oop5.variance.contravariance
 *
 * @see \Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeContravariantArgumentTypeRector\DowngradeContravariantArgumentTypeRectorTest
 */
final class DowngradeContravariantArgumentTypeRector extends AbstractRector
{
    private bool $hasChanged = false;

    public function __construct(
        private readonly PhpDocTypeChanger $phpDocTypeChanger,
        private readonly ParamAnalyzer $paramAnalyzer,
        private readonly ReflectionResolver $reflectionResolver,
        private readonly PhpDocInfoFactory $phpDocInfoFactory,
        private readonly StaticTypeMapper $staticTypeMapper
    ) {
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [ClassMethod::class, Function_::class];
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Remove contravariant argument type declarations', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class ParentType {}
class ChildType extends ParentType {}

class A
{
    public function contraVariantArguments(ChildType $type)
    {
    }
}

class B extends A
{
    public function contraVariantArguments(ParentType $type)
    {
    }
}
CODE_SAMPLE
                ,
                <<<'CODE_SAMPLE'
class ParentType {}
class ChildType extends ParentType {}

class A
{
    public function contraVariantArguments(ChildType $type)
    {
    }
}

class B extends A
{
    /**
     * @param ParentType $type
     */
    public function contraVariantArguments($type)
    {
    }
}
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @param ClassMethod|Function_ $node
     */
    public function refactor(Node $node): ?Node
    {
        if ($node->params === []) {
            return null;
        }

        $this->hasChanged = false;
        foreach ($node->params as $param) {
            $this->refactorParam($param, $node);
        }

        if ($this->hasChanged) {
            return $node;
        }

        return null;
    }

    private function isNullableParam(Param $param, ClassMethod|Function_ $functionLike): bool
    {
        if ($param->variadic) {
            return false;
        }

        if (! $param->type instanceof Node) {
            return false;
        }

        // Don't consider for Union types
        if ($param->type instanceof UnionType) {
            return false;
        }

        // Contravariant arguments are supported for __construct
        if ($this->isName($functionLike, MethodName::CONSTRUCT)) {
            return false;
        }

        // Check if the type is different from the one declared in some ancestor
        return $this->getDifferentParamTypeFromAncestorClass($param, $functionLike) !== null;
    }

    private function getDifferentParamTypeFromAncestorClass(Param $param, ClassMethod|Function_ $functionLike): ?string
    {
        $classReflection = $this->reflectionResolver->resolveClassReflection($functionLike);
        if (! $classReflection instanceof ClassReflection) {
            return null;
        }

        $paramName = $this->getName($param);

        // If it is the NullableType, extract the name from its inner type
        /** @var Node $paramType */
        $paramType = $param->type;

        if ($this->paramAnalyzer->isNullable($param)) {
            /** @var NullableType $nullableType */
            $nullableType = $paramType;
            $paramTypeName = $this->getName($nullableType->type);
        } else {
            $paramTypeName = $this->getName($paramType);
        }

        if ($paramTypeName === null) {
            return null;
        }

        /** @var string $methodName */
        $methodName = $this->getName($functionLike);

        // parent classes or implemented interfaces
        /** @var ClassReflection[] $parentClassReflections */
        $parentClassReflections = [...$classReflection->getParents(), ...$classReflection->getInterfaces()];

        foreach ($parentClassReflections as $parentClassReflection) {
            $parentReflectionMethod = $this->resolveParentReflectionMethod($parentClassReflection, $methodName);

            if (! $parentReflectionMethod instanceof ReflectionMethod) {
                continue;
            }

            $differentAncestorParamTypeName = $this->getDifferentParamTypeFromReflectionMethod(
                $parentReflectionMethod,
                $paramName,
                $paramTypeName
            );

            if ($differentAncestorParamTypeName !== null) {
                return $differentAncestorParamTypeName;
            }
        }

        return null;
    }

    private function resolveParentReflectionMethod(
        ClassReflection $classReflection,
        string $methodName
    ): ?ReflectionMethod {
        if (! $classReflection->hasMethod($methodName)) {
            return null;
        }

        $nativeReflection = $classReflection->getNativeReflection();

        if (! $nativeReflection->hasMethod($methodName)) {
            return null;
        }

        // Find the param we're looking for
        return $nativeReflection->getMethod($methodName);
    }

    private function getDifferentParamTypeFromReflectionMethod(
        ReflectionMethod $reflectionMethod,
        string $paramName,
        string $paramTypeName
    ): ?string {
        /** @var ReflectionParameter[] $parentReflectionMethodParams */
        $parentReflectionMethodParams = $reflectionMethod->getParameters();

        foreach ($parentReflectionMethodParams as $parentReflectionMethodParam) {
            if ($parentReflectionMethodParam->getName() === $paramName) {
                /**
                 * Getting a ReflectionNamedType works from PHP 7.1 onwards
                 * @see https://www.php.net/manual/en/reflectionparameter.gettype.php#125334
                 */
                $reflectionParamType = $parentReflectionMethodParam->getType();

                /**
                 * If the type is null, we don't have enough information
                 * to check if they are different. Then do nothing
                 */
                if (! $reflectionParamType instanceof ReflectionNamedType) {
                    continue;
                }

                if ($reflectionParamType->getName() !== $paramTypeName) {
                    // We found it: a different param type in some ancestor
                    return $reflectionParamType->getName();
                }
            }
        }

        return null;
    }

    private function refactorParam(Param $param, ClassMethod | Function_ $functionLike): void
    {
        if (! $this->isNullableParam($param, $functionLike)) {
            return;
        }

        $this->decorateWithDocBlock($functionLike, $param);
        $param->type = null;

        $this->hasChanged = true;
    }

    private function decorateWithDocBlock(ClassMethod | Function_ $functionLike, Param $param): void
    {
        if (! $param->type instanceof Node) {
            return;
        }

        $type = $this->staticTypeMapper->mapPhpParserNodePHPStanType($param->type);
        $paramName = $this->getName($param->var) ?? '';

        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($functionLike);
        $this->phpDocTypeChanger->changeParamType($functionLike, $phpDocInfo, $type, $param, $paramName);
    }
}
