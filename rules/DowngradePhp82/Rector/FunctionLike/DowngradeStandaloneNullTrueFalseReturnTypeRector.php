<?php

declare(strict_types=1);

namespace Rector\DowngradePhp82\Rector\FunctionLike;

use PhpParser\Node;
use PhpParser\Node\Expr\ArrowFunction;
use PhpParser\Node\Expr\Closure;
use PhpParser\Node\FunctionLike;
use PhpParser\Node\Identifier;
use PhpParser\Node\Stmt\ClassMethod;
use PhpParser\Node\Stmt\Function_;
use PHPStan\Type\Constant\ConstantBooleanType;
use PHPStan\Type\NullType;
use PHPStan\Type\Type;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfoFactory;
use Rector\BetterPhpDocParser\PhpDocManipulator\PhpDocTypeChanger;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/null-false-standalone-types
 * @changelog https://wiki.php.net/rfc/true-type
 * @see \Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\DowngradeStandaloneNullTrueFalseReturnTypeRectorTest
 */
final class DowngradeStandaloneNullTrueFalseReturnTypeRector extends AbstractRector
{
    public function __construct(
        private readonly PhpDocInfoFactory $phpDocInfoFactory,
        private readonly PhpDocTypeChanger $phpDocTypeChanger
    ) {
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [FunctionLike::class];
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Downgrade standalone return null, true, or false',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
final class SomeClass
{
    public function run(): null
    {
        return null;
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
final class SomeClass
{
    public function run(): mixed
    {
        return null;
    }
}
CODE_SAMPLE
                ),
            ]
        );
    }

    /**
     * @param ClassMethod|Function_|Closure|ArrowFunction $node
     */
    public function refactor(Node $node): ?Node
    {
        $returnType = $node->getReturnType();
        if (! $returnType instanceof Node) {
            return null;
        }

        $returnTypeName = $this->getName($returnType);
        if (! in_array($returnTypeName, ['null', 'false', 'true'], true)) {
            return null;
        }

        if (! $node instanceof ClassMethod) {
            // in closure and arrow function can't add `@return null` docblock as they are Expr
            // that rely on Stmt
            $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($node);
            $this->phpDocTypeChanger->changeReturnType($node, $phpDocInfo, $this->resolveType($node->returnType));

            $node->returnType = $this->resolveNativeType($node->returnType);
            return $node;
        }

        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($node);
        $this->phpDocTypeChanger->changeReturnType($node, $phpDocInfo, $this->resolveType($node->returnType));

        // todo: verify parent
        $node->returnType = $this->resolveNativeType($node->returnType);

        return $node;
    }

    private function resolveType(Node $node): Type
    {
        $nodeName = $this->getName($node);

        if ($nodeName === 'null') {
            return new NullType();
        }

        if ($nodeName === 'false') {
            return new ConstantBooleanType(false);
        }

        return new ConstantBooleanType(true);
    }

    private function resolveNativeType($node): Identifier
    {
        $nodeName = $this->getName($node);

        if ($nodeName === 'null') {
            return new Identifier('mixed');
        }

        return new Identifier('bool');
    }
}
