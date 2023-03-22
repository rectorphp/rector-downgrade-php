<?php

declare(strict_types=1);

namespace Rector\DowngradePhp74\Rector\Array_;

use PhpParser\Node;
use PhpParser\Node\Expr\Array_;
use PhpParser\Node\Expr\ArrayItem;
use PhpParser\Node\Expr\ClassConstFetch;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;
use PhpParser\Node\Scalar\String_;
use PhpParser\Node\Stmt\ClassConst;
use PhpParser\Node\Stmt\ClassLike;
use PHPStan\Analyser\MutatingScope;
use PHPStan\Analyser\Scope;
use Rector\Core\PhpParser\Printer\BetterStandardPrinter;
use Rector\Core\Rector\AbstractScopeAwareRector;
use Rector\DowngradePhp81\NodeAnalyzer\ArraySpreadAnalyzer;
use Rector\DowngradePhp81\NodeFactory\ArrayMergeFromArraySpreadFactory;
use Rector\NodeTypeResolver\Node\AttributeKey;
use Rector\StaticTypeMapper\ValueObject\Type\FullyQualifiedObjectType;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/spread_operator_for_array
 *
 * @see \Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\DowngradeArraySpreadRectorTest
 */
final class DowngradeArraySpreadRector extends AbstractScopeAwareRector
{
    public function __construct(
        private readonly ArrayMergeFromArraySpreadFactory $arrayMergeFromArraySpreadFactory,
        private readonly ArraySpreadAnalyzer $arraySpreadAnalyzer,
        private readonly BetterStandardPrinter $betterStandardPrinter
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Replace array spread with array_merge function',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        $parts = ['apple', 'pear'];
        $fruits = ['banana', 'orange', ...$parts, 'watermelon'];
    }

    public function runWithIterable()
    {
        $fruits = ['banana', 'orange', ...new ArrayIterator(['durian', 'kiwi']), 'watermelon'];
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        $parts = ['apple', 'pear'];
        $fruits = array_merge(['banana', 'orange'], $parts, ['watermelon']);
    }

    public function runWithIterable()
    {
        $item0Unpacked = new ArrayIterator(['durian', 'kiwi']);
        $fruits = array_merge(['banana', 'orange'], is_array($item0Unpacked) ? $item0Unpacked : iterator_to_array($item0Unpacked), ['watermelon']);
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
        return [Array_::class];
    }

    /**
     * @param Array_ $node
     * @return null|FuncCall|ArrayItem
     */
    public function refactorWithScope(Node $node, Scope $scope)
    {
        if (! $this->arraySpreadAnalyzer->isArrayWithUnpack($node)) {
            return null;
        }

        $classConst = $this->betterNodeFinder->findParentType($node, ClassConst::class);
        if ($classConst instanceof ClassConst) {
            $parentClassConst = $classConst->getAttribute(AttributeKey::PARENT_NODE);
            if ($parentClassConst instanceof ClassLike) {
                $className = (string) $this->getName($parentClassConst);
                foreach ($node->items as $key => $item) {
                    if ($item instanceof ArrayItem && $item->unpack && $item->value instanceof ClassConstFetch && $item->value->class instanceof Name) {
                        $type = $this->nodeTypeResolver->getType($item->value->class);
                        $name = $item->value->name;
                        if ($type instanceof FullyQualifiedObjectType && $name instanceof Identifier && $type->getClassName() === $className) {
                            $constants = $parentClassConst->getConstants();
                            foreach ($constants as $constant) {
                                if ($constant->consts[0]->name instanceof Identifier && $constant->consts[0]->name->toString() === $name->toString()) {
                                    $newItem = trim(
                                        $this->betterStandardPrinter->print($constant->consts[0]->value),
                                        '([)]'
                                    );
                                    $node->items[$key] = new ArrayItem(new String_($newItem));
                                    continue 2;
                                }
                            }
                        }
                    }
                }
            }

            return $node;
        }

        $shouldIncrement = (bool) $this->betterNodeFinder->findFirstNext($node, function (Node $subNode): bool {
            if (! $subNode instanceof Array_) {
                return false;
            }

            return $this->arraySpreadAnalyzer->isArrayWithUnpack($subNode);
        });

        /** @var MutatingScope $scope */
        return $this->arrayMergeFromArraySpreadFactory->createFromArray($node, $scope, $this->file, $shouldIncrement);
    }
}
