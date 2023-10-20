<?php

declare(strict_types=1);

namespace Rector\DowngradePhp81\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Arg;
use PhpParser\Node\Expr\ConstFetch;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Scalar\String_;
use Rector\Core\Exception\ShouldNotHappenException;
use Rector\Core\NodeAnalyzer\ArgsAnalyzer;
use Rector\Core\PhpParser\Node\Value\ValueResolver;
use Rector\Core\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp81\Rector\FuncCall\DowngradeHashAlgorithmXxHash\DowngradeHashAlgorithmXxHashRectorTest
 */
final class DowngradeHashAlgorithmXxHashRector extends AbstractRector
{
    private const HASH_ALGORITHMS_TO_DOWNGRADE = [
        'xxh32' => MHASH_XXH32,
        'xxh64' => MHASH_XXH64,
        'xxh3' => MHASH_XXH3,
        'xxh128' => MHASH_XXH128,
    ];

    private const REPLACEMENT_ALGORITHM = 'md5';

    private int $argNamedKey;

    public function __construct(
        private readonly ArgsAnalyzer $argsAnalyzer,
        private readonly ValueResolver $valueResolver,
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Downgrade hash algorithm xxh32, xxh64, xxh3 or xxh128 by default to md5. You can configure the algorithm to downgrade.',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        return hash('xxh128', 'some-data-to-hash');
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function run()
    {
        return hash('md5', 'some-data-to-hash');
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
        return [FuncCall::class];
    }

    /**
     * @param FuncCall $node
     */
    public function refactor(Node $node): ?Node
    {
        if ($this->shouldSkip($node)) {
            return null;
        }

        $this->argNamedKey = 0;

        $algorithm = $this->getHashAlgorithm($node->getArgs());

        if (! array_key_exists($algorithm, self::HASH_ALGORITHMS_TO_DOWNGRADE)) {
            return null;
        }

        $arg = $node->args[$this->argNamedKey];

        if (! $arg instanceof Arg) {
            throw new ShouldNotHappenException();
        }

        $arg->value = new String_(self::REPLACEMENT_ALGORITHM);

        return $node;
    }

    private function shouldSkip(FuncCall $funcCall): bool
    {
        if ($funcCall->isFirstClassCallable()) {
            return true;
        }

        return ! $this->nodeNameResolver->isName($funcCall, 'hash');
    }

    /**
     * @param Arg[] $args
     */
    private function getHashAlgorithm(array $args): ?string
    {
        $arg = null;

        if ($this->argsAnalyzer->hasNamedArg($args)) {
            foreach ($args as $key => $arg) {
                if ($arg->name?->name !== 'algo') {
                    continue;
                }

                $this->argNamedKey = $key;

                break;
            }
        } else {
            $arg = $args[$this->argNamedKey];
        }

        $algorithmNode = $arg?->value;

        return match (true) {
            $algorithmNode instanceof String_ => $this->valueResolver->getValue($algorithmNode),
            $algorithmNode instanceof ConstFetch => $this->mapConstantToString(
                $this->valueResolver->getValue($algorithmNode)
            ),
            default => null,
        };
    }

    private function mapConstantToString(string $constant): string
    {
        $mappedConstant = array_search(constant($constant), self::HASH_ALGORITHMS_TO_DOWNGRADE, true);

        return $mappedConstant !== false ? $mappedConstant : $constant;
    }
}
