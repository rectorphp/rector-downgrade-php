<?php

declare(strict_types=1);

namespace Rector\DowngradePhp82\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Arg;
use PhpParser\Node\Expr;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\New_;
use PhpParser\Node\Expr\Ternary;
use PhpParser\Node\Name\FullyQualified;
use PHPStan\Type\Type;
use PHPStan\Type\UnionType;
use Rector\NodeAnalyzer\ArgsAnalyzer;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://www.php.net/manual/en/migration82.other-changes.php#migration82.other-changes.functions.spl
 *
 * @see \Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\DowngradeIteratorCountToArrayRectorTest
 * @see https://3v4l.org/TPW7a#v8.1.31
 */
final class DowngradeIteratorCountToArrayRector extends AbstractRector
{
    public function __construct(
        private readonly ArgsAnalyzer $argsAnalyzer
    ) {
    }

    /**
     * @return array<class-string<Node>>
     */
    public function getNodeTypes(): array
    {
        return [FuncCall::class];
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Ensure pass Traversable instance before use in iterator_count() and iterator_to_array()',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
function test(array|Traversable $data) {
    $c = iterator_count($data);
    $v = iterator_to_array($data);
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
function test(array|Traversable $data) {
    $c = iterator_count(is_array($data) ? new ArrayIterator($data) : $data);
    $v = iterator_to_array(is_array($data) ? new ArrayIterator($data) : $data);
}
CODE_SAMPLE
                ),
            ]
        );
    }

    /**
     * @param FuncCall $node
     */
    public function refactor(Node $node): ?Node
    {
        if (! $this->isNames($node, ['iterator_count', 'iterator_to_array'])) {
            return null;
        }

        if ($node->isFirstClassCallable()) {
            return null;
        }

        $args = $node->getArgs();
        if ($this->argsAnalyzer->hasNamedArg($args)) {
            return null;
        }

        if (! isset($args[0])) {
            return null;
        }

        $type = $this->nodeTypeResolver->getType($args[0]->value);
        if ($this->shouldSkip($type, $args[0]->value)) {
            return null;
        }

        $firstValue = $node->args[0]->value;
        $node->args[0]->value = new Ternary(
            $this->nodeFactory->createFuncCall('is_array', [new Arg($firstValue)]),
            new New_(new FullyQualified('ArrayIterator'), [new Arg($firstValue)]),
            $firstValue
        );

        return $node;
    }

    private function shouldSkip(Type $type, Expr $expr): bool
    {
        // only array type
        if ($type->isArray()->yes()) {
            return false;
        }

        if ($type instanceof UnionType) {
            // possibly already transformed
            return $expr instanceof Ternary;
        }

        // already has object type check
        return $type->isObject()->yes();
    }
}
