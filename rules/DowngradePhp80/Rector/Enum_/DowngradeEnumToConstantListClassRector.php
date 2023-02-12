<?php

declare(strict_types=1);

namespace Rector\DowngradePhp80\Rector\Enum_;

use PhpParser\Node;
use PhpParser\Node\ComplexType;
use PhpParser\Node\Expr\PropertyFetch;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;
use PhpParser\Node\NullableType;
use PhpParser\Node\Param;
use PhpParser\Node\Stmt\ClassLike;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Enum_;
use PhpParser\Node\UnionType;
use PHPStan\PhpDocParser\Ast\ConstExpr\ConstFetchNode;
use PHPStan\PhpDocParser\Ast\PhpDoc\ParamTagValueNode;
use PHPStan\PhpDocParser\Ast\Type\ConstTypeNode;
use PHPStan\PhpDocParser\Ast\Type\IdentifierTypeNode;
use PHPStan\PhpDocParser\Ast\Type\NullableTypeNode;
use PHPStan\PhpDocParser\Ast\Type\UnionTypeNode;
use PHPStan\Reflection\ClassReflection;
use PHPStan\Reflection\ReflectionProvider;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfo;
use Rector\Core\Rector\AbstractRector;
use Rector\DowngradePhp80\NodeAnalyzer\EnumAnalyzer;
use Rector\NodeFactory\ClassFromEnumFactory;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp80\Rector\Enum_\DowngradeEnumToConstantListClassRector\DowngradeEnumToConstantListClassRectorTest
 */
final class DowngradeEnumToConstantListClassRector extends AbstractRector
{
    public function __construct(
        private readonly ClassFromEnumFactory $classFromEnumFactory,
        private readonly ReflectionProvider $reflectionProvider,
        private readonly EnumAnalyzer $enumAnalyzer,
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Downgrades enum and all it\'s usages to constant list class replaced the enum references to the enum baking type',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
enum Direction: string
{
    case LEFT = 'left';
    case RIGHT = 'right';

    public function check(null|self|Enum|string $value): self
    {
        ...
    }
}
CODE_SAMPLE

                    ,
                    <<<'CODE_SAMPLE'
class Direction
{
    public const LEFT = 'left';
    public const RIGHT = 'right';
    /**
     * @param (null | \Direction::* | string) $value
     */
    public function check(null|string $value): string
    {

    }
}
CODE_SAMPLE
                ),
            ]
        );
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [Enum_::class, ClassMethod::class, PropertyFetch::class];
    }

    /**
     * @param Enum_|ClassMethod $node
     */
    public function refactor(Node $node): mixed
    {
        if ($node instanceof Enum_) {
            return $this->classFromEnumFactory->createFromEnum($node);
        }
        if ($node instanceof PropertyFetch) {
            return $this->replaceEnumToConstant($node);
        }

        $hasChanged = false;
        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($node);

        foreach ($node->params as $param) {
            $this->decorateParamDocType($param, $phpDocInfo);
            $param->type = $this->renameEnumReference($param->type);

            $hasChanged = true;
        }
        if ($node->returnType !== null) {
            $oldReturnType = $node->returnType;

            $node->returnType = $this->renameEnumReference($node->returnType);
            if ($oldReturnType !== $node->returnType) {
                $hasChanged = true;
            }
        }

        if ($hasChanged) {
            return $node;
        }

        return null;
    }

    private function decorateParamDocType(Param $param, PhpDocInfo $phpDocInfo): void
    {
        $nullable = false;
        $paramType = $param->type;
        if ($paramType instanceof UnionType) {
            $types = [];
            foreach ($paramType->types as $type) {
                $classLikeReflection = $this->getClassReflectionByType($type);
                if ($classLikeReflection === null) {
                    $types[] = $type;
                    continue;
                }
                $constFetchNode = new ConstFetchNode('\\' . $classLikeReflection->getName(), '*');
                $types[$classLikeReflection->getName()] = new ConstTypeNode($constFetchNode);
            }
            $paramTypeNode = count($types) > 1 ? new UnionTypeNode($types) : new IdentifierTypeNode((string) $types[0]);
        } else {
            $nullable = $paramType instanceof NullableType;
            $classLikeReflection = $this->getClassReflectionByType($paramType);
            $typeName = $this->getName($paramType);
            $typeNode = $classLikeReflection !== null
                ? new ConstTypeNode(new ConstFetchNode('\\' . $classLikeReflection->getName(), '*'))
                : new IdentifierTypeNode($typeName);
            $paramTypeNode = $typeNode;
        }
        $paramTypeNode = $nullable ? new NullableTypeNode($paramTypeNode) : $paramTypeNode;
        $paramName = '$' . $this->getName($param);

        $paramTagValueNode = new ParamTagValueNode($paramTypeNode, false, $paramName, '');
        $phpDocInfo->addTagValueNode($paramTagValueNode);
    }

    private function replaceEnumToConstant(PropertyFetch $node): PropertyFetch|Node\Expr|Node\Scalar\String_
    {
        if ((string) $node->name === 'value') {
            return $node->var;
        }
        if ((string) $node->name === 'name') {
            return new Node\Scalar\String_($node->var->name->toString());
        }

        return $node;
    }

    private function renameEnumReference(null|ComplexType|Identifier|Name $type): null|ComplexType|Identifier|Name
    {
        if ($type instanceof UnionType) {
            $types = [];
            foreach ($type->types as &$innerType) {
                $newType = $this->renameEnumReference($innerType);
                $types[(string) $newType] = $newType;
            }
            $type->types = $types;
            return $type;
        }

        $classLikeReflection = $this->getClassReflectionByType($type);
        if ($classLikeReflection === null) {
            return $type;
        }
        $identifier = $this->enumAnalyzer->resolveType($classLikeReflection);

        if ($identifier !== null) {
            if ($type instanceof NullableType) {
                return new NullableType((string) $identifier);
            }
            return $identifier;
        }

        return null;
    }

    private function getClassReflectionByType(null|ComplexType|Identifier|Name $type): ?ClassReflection
    {
        if ($type instanceof UnionType) {
            foreach ($type->types as $type) {
                $classReflection = $this->getClassReflectionByType($type);
                if ($classReflection instanceof ClassReflection) {
                    if ($classReflection->isEnum()) {
                        return $classReflection;
                    }
                }
            }
            return null;
        }
        $typeName = $type instanceof NullableType ? (string) $type->type : (string) $type;
        if (in_array($typeName, ['self', 'static'], true)) {
            $class = $this->betterNodeFinder->findParentType($type, ClassLike::class);
            return $this->reflectionProvider->getClass($this->getName($class));
        }
        if ($this->reflectionProvider->hasClass($typeName)) {
            return $this->reflectionProvider->getClass($typeName);
        }
        return null;
    }
}
