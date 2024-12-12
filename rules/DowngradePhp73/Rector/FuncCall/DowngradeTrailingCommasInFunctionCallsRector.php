<?php

declare(strict_types=1);

namespace Rector\DowngradePhp73\Rector\FuncCall;

use PhpParser\Node;
use PhpParser\Node\Expr\FuncCall;
use PhpParser\Node\Expr\MethodCall;
use PhpParser\Node\Expr\New_;
use PhpParser\Node\Expr\StaticCall;
use Rector\DowngradePhp73\Tokenizer\FollowedByCommaAnalyzer;
use Rector\Rector\AbstractRector;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @see \Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeTrailingCommasInFunctionCallsRector\DowngradeTrailingCommasInFunctionCallsRectorTest
 */
final class DowngradeTrailingCommasInFunctionCallsRector extends AbstractRector
{
    public function __construct(
        private readonly FollowedByCommaAnalyzer $followedByCommaAnalyzer
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition(
            'Remove trailing commas in function calls',
            [
                new CodeSample(
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function __construct(string $value)
    {
        $compacted = compact(
            'posts',
            'units',
        );
    }
}
CODE_SAMPLE
                    ,
                    <<<'CODE_SAMPLE'
class SomeClass
{
    public function __construct(string $value)
    {
        $compacted = compact(
            'posts',
            'units'
        );
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
        return [FuncCall::class, MethodCall::class, StaticCall::class, New_::class];
    }

    /**
     * @param FuncCall|MethodCall|StaticCall|New_ $node
     */
    public function refactor(Node $node): ?Node
    {
        if ($node->isFirstClassCallable()) {
            return null;
        }

        $args = $node->getArgs();
        if ($args === []) {
            return null;
        }

        $lastArgKey = count($args) - 1;

        $lastArg = $args[$lastArgKey];
        if (! $this->followedByCommaAnalyzer->isFollowed($this->file, $lastArg)) {
            return null;
        }

        $tokens = $this->file->getOldTokens();
        $iteration = 1;

        while (isset($tokens[$args[$lastArgKey]->getEndTokenPos() + $iteration])) {
            if (trim($tokens[$args[$lastArgKey]->getEndTokenPos() + $iteration]->text) === ',') {
                $tokens[$args[$lastArgKey]->getEndTokenPos() + $iteration]->text = '';
                break;
            }

            ++$iteration;
        }

        return $node;
    }
}
