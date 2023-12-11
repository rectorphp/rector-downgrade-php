<?php

declare(strict_types=1);

namespace Rector\DowngradePhp82\Rector\FunctionLike;

use PhpParser\Node;
use PhpParser\Node\FunctionLike;
use PhpParser\Node\Identifier;
use PhpParser\Node\Stmt\ClassMethod;
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
     * @param FunctionLike $node
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
            $node->returnType = new Identifier('mixed');
            return $node;
        }

        // todo: verify parent
        $node->returnType = new Identifier('mixed');
        return null;
    }
}
