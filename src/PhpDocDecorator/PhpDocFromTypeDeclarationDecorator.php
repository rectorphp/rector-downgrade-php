<?php

declare(strict_types=1);

namespace Rector\PhpDocDecorator;

use PhpParser\Node\ComplexType;
use PhpParser\Node\Expr\ArrowFunction;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;
use PhpParser\Node\Param;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Function_;
use PHPStan\PhpDocParser\Ast\PhpDoc\ReturnTagValueNode;
use PHPStan\Reflection\ClassReflection;
use PHPStan\Type\MixedType;
use PHPStan\Type\ObjectType;
use PHPStan\Type\ThisType;
use PHPStan\Type\Type;
use PHPStan\Type\TypeCombinator;
use PHPStan\Type\UnionType;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfoFactory;
use Rector\BetterPhpDocParser\PhpDocManipulator\PhpDocTypeChanger;
use Rector\Core\Php\PhpVersionProvider;
use Rector\Core\Reflection\ReflectionResolver;
use Rector\Core\ValueObject\PhpVersionFeature;
use Rector\NodeNameResolver\NodeNameResolver;
use Rector\Php80\NodeAnalyzer\PhpAttributeAnalyzer;
use Rector\PhpAttribute\NodeFactory\PhpAttributeGroupFactory;
use Rector\PHPStanStaticTypeMapper\Enum\TypeKind;
use Rector\StaticTypeMapper\StaticTypeMapper;
use Rector\StaticTypeMapper\ValueObject\Type\SelfStaticType;
use Rector\ValueObject\ClassMethodWillChangeReturnType;

/**
 * @see https://wiki.php.net/rfc/internal_method_return_types#proposal
 */
final class PhpDocFromTypeDeclarationDecorator
{
    /**
     * @var ClassMethodWillChangeReturnType[]
     */
    private array $classMethodWillChangeReturnTypes = [];

    public function __construct(
        private readonly StaticTypeMapper $staticTypeMapper,
        private readonly PhpDocInfoFactory $phpDocInfoFactory,
        private readonly NodeNameResolver $nodeNameResolver,
        private readonly PhpDocTypeChanger $phpDocTypeChanger,
        private readonly PhpAttributeGroupFactory $phpAttributeGroupFactory,
        private readonly ReflectionResolver $reflectionResolver,
        private readonly PhpAttributeAnalyzer $phpAttributeAnalyzer,
        private readonly PhpVersionProvider $phpVersionProvider
    ) {
        $this->classMethodWillChangeReturnTypes = [
            // @todo how to make list complete? is the method list needed or can we use just class names?
            new ClassMethodWillChangeReturnType('ArrayAccess', 'offsetGet'),
            new ClassMethodWillChangeReturnType('ArrayAccess', 'getIterator'),
        ];
    }

    public function decorateReturn(ClassMethod|Function_|Closure|ArrowFunction $functionLike): void
    {
        if ($functionLike->returnType === null) {
            return;
        }

        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($functionLike);

        $returnTagValueNode = $phpDocInfo->getReturnTagValue();
        $returnType = $returnTagValueNode instanceof ReturnTagValueNode
            ? $this->staticTypeMapper->mapPHPStanPhpDocTypeToPHPStanType($returnTagValueNode, $functionLike->returnType)
            : $this->staticTypeMapper->mapPhpParserNodePHPStanType($functionLike->returnType);

        // if nullable is supported, downgrade to that one
        if ($this->isNullableSupportedAndPossible($returnType)) {
            $functionLike->returnType = $this->staticTypeMapper->mapPHPStanTypeToPhpParserNode(
                $returnType,
                TypeKind::RETURN
            );

            return;
        }

        $this->phpDocTypeChanger->changeReturnType($functionLike, $phpDocInfo, $returnType);

        $functionLike->returnType = null;
        if (! $functionLike instanceof ClassMethod) {
            return;
        }

        $classReflection = $this->reflectionResolver->resolveClassReflection($functionLike);
        if (! $classReflection instanceof ClassReflection || (! $classReflection->isInterface() && ! $classReflection->isClass())) {
            return;
        }

        if (! $this->isRequireReturnTypeWillChange($classReflection, $functionLike)) {
            return;
        }

        $functionLike->attrGroups[] = $this->phpAttributeGroupFactory->createFromClass('ReturnTypeWillChange');
    }

    /**
     * @param array<class-string<Type>> $requiredTypes
     */
    public function decorateParam(
        Param $param,
        ClassMethod|Function_|Closure|ArrowFunction $functionLike,
        array $requiredTypes
    ): void {
        if ($param->type === null) {
            return;
        }

        $type = $this->staticTypeMapper->mapPhpParserNodePHPStanType($param->type);
        if (! $this->isMatchingType($type, $requiredTypes)) {
            return;
        }

        if ($this->isNullableSupportedAndPossible($type)) {
            $param->type = $this->staticTypeMapper->mapPHPStanTypeToPhpParserNode($type, TypeKind::PARAM);
            return;
        }

        $this->moveParamTypeToParamDoc($functionLike, $param, $type);
    }

    public function decorateParamWithSpecificType(
        Param $param,
        ClassMethod|Function_|Closure|ArrowFunction $functionLike,
        Type $requireType
    ): bool {
        if ($param->type === null) {
            return false;
        }

        if (! $this->isTypeMatch($param->type, $requireType)) {
            return false;
        }

        $type = $this->staticTypeMapper->mapPhpParserNodePHPStanType($param->type);

        if ($this->isNullableSupportedAndPossible($type)) {
            $param->type = $this->staticTypeMapper->mapPHPStanTypeToPhpParserNode($type, TypeKind::PARAM);
            return true;
        }

        $this->moveParamTypeToParamDoc($functionLike, $param, $type);
        return true;
    }

    /**
     * @return bool True if node was changed
     */
    public function decorateReturnWithSpecificType(
        ClassMethod|Function_|Closure|ArrowFunction $functionLike,
        Type $requireType
    ): bool {
        if ($functionLike->returnType === null) {
            return false;
        }

        if (! $this->isTypeMatch($functionLike->returnType, $requireType)) {
            return false;
        }

        $this->decorateReturn($functionLike);
        return true;
    }

    private function isRequireReturnTypeWillChange(ClassReflection $classReflection, ClassMethod $classMethod): bool
    {
        if ($classReflection->isAnonymous()) {
            return false;
        }

        $methodName = $classMethod->name->toString();

        // support for will return change type in case of removed return doc type
        // @see https://php.watch/versions/8.1/ReturnTypeWillChange
        foreach ($this->classMethodWillChangeReturnTypes as $classMethodWillChangeReturnType) {
            if ($classMethodWillChangeReturnType->getMethodName() !== $methodName) {
                continue;
            }

            if (! $classReflection->isSubclassOf($classMethodWillChangeReturnType->getClassName())) {
                continue;
            }

            if ($this->phpAttributeAnalyzer->hasPhpAttribute($classMethod, 'ReturnTypeWillChange')) {
                continue;
            }

            return true;
        }

        return false;
    }

    private function isTypeMatch(ComplexType|Identifier|Name $typeNode, Type $requireType): bool
    {
        $returnType = $this->staticTypeMapper->mapPhpParserNodePHPStanType($typeNode);

        if ($returnType instanceof SelfStaticType) {
            $returnType = new ThisType($returnType->getClassReflection());
        }

        // cover nullable union types
        if ($returnType instanceof UnionType) {
            $returnType = TypeCombinator::removeNull($returnType);
        }

        if ($returnType instanceof ObjectType) {
            return $returnType->equals($requireType);
        }

        return $returnType::class === $requireType::class;
    }

    private function moveParamTypeToParamDoc(
        ClassMethod|Function_|Closure|ArrowFunction $functionLike,
        Param $param,
        Type $type
    ): void {
        $param->type = null;

        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($functionLike);
        $paramName = $this->nodeNameResolver->getName($param);

        $phpDocParamType = $phpDocInfo->getParamType($paramName);
        if (! $type instanceof MixedType && $type::class === $phpDocParamType::class) {
            return;
        }

        $this->phpDocTypeChanger->changeParamType($functionLike, $phpDocInfo, $type, $param, $paramName);
    }

    /**
     * @param array<class-string<Type>> $requiredTypes
     */
    private function isMatchingType(Type $type, array $requiredTypes): bool
    {
        return in_array($type::class, $requiredTypes, true);
    }

    private function isNullableSupportedAndPossible(Type $type): bool
    {
        if (! $this->phpVersionProvider->isAtLeastPhpVersion(PhpVersionFeature::NULLABLE_TYPE)) {
            return false;
        }

        if (! $type instanceof UnionType) {
            return false;
        }

        if (count($type->getTypes()) !== 2) {
            return false;
        }

        return TypeCombinator::containsNull($type);
    }
}
