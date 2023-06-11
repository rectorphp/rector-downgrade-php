<?php

declare(strict_types=1);

namespace Rector\DowngradePhp74\Rector\MethodCall;

use PhpParser\Node;
use PhpParser\Node\Arg;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\Instanceof_;
use PhpParser\Node\Expr\MethodCall;
use PhpParser\Node\Expr\Ternary;
use PhpParser\Node\Scalar\String_;
use PHPStan\Type\ObjectType;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp74\Rector\MethodCall\DowngradeReflectionGetTypeRector\DowngradeReflectionGetTypeRectorTest
 */
final class DowngradeReflectionGetTypeRector extends AbstractRector
{
    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Downgrade reflection $reflection->getType() method call', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run(ReflectionProperty $reflectionProperty)
    {
        if ($reflectionProperty->getType()) {
            return true;
        }

        return false;
    }
}
CODE_SAMPLE

                ,
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function run(ReflectionProperty $reflectionProperty)
    {
        if (null) {
            return true;
        }

        return false;
    }
}
CODE_SAMPLE
            ),
        ]);
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [MethodCall::class, Ternary::class, Instanceof_::class];
    }

    /**
     * @param MethodCall|Ternary|Instanceof_ $node
     */
    public function refactor(Node $node): Node|null|int
    {
        if ($node instanceof Instanceof_) {
            if ($this->isName($node->class, 'ReflectionNamedType') && $node->expr instanceof MethodCall) {
                // checked typed → safe
                $node->expr->setAttribute('skip_node', true);
            }

            return null;
        }

        if ($node instanceof Ternary) {
            if ($node->if instanceof Expr
                && $node->cond instanceof FuncCall
                && $this->isName($node->cond, 'method_exists')) {
                $node->if->setAttribute('skip_node', true);
            }

            return null;
        }

        if ($node->getAttribute('skip_node') === true) {
            return null;
        }

        if (! $this->isName($node->name, 'getType')) {
            return null;
        }

        if (! $this->isObjectType($node->var, new ObjectType('ReflectionProperty'))) {
            return null;
        }

        $args = [new Arg($node->var), new Arg(new String_('getType'))];

        return new Ternary(
            $this->nodeFactory->createFuncCall('method_exists', $args),
            $node,
            $this->nodeFactory->createNull()
        );
    }
}
