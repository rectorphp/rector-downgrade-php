<?php

declare(strict_types=1);

namespace Rector\DowngradePhp85\Rector\Class_;

use PhpParser\Builder\Property;
use PhpParser\Modifiers;
use PhpParser\Node;
use PhpParser\Node\Param;
use PhpParser\Node\Stmt\ClassMethod;
use PHPStan\PhpDocParser\Ast\PhpDoc\GenericTagValueNode;
use PHPStan\PhpDocParser\Ast\PhpDoc\PhpDocTagNode;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfoFactory;
use Rector\Comments\NodeDocBlock\DocBlockUpdater;
use Rector\Privatization\NodeManipulator\VisibilityManipulator;
use Rector\Rector\AbstractRector;
use Rector\ValueObject\MethodName;
use Rector\ValueObject\Visibility;
use Symplify\RuleDocGenerator\ValueObject\CodeSample\CodeSample;
use Symplify\RuleDocGenerator\ValueObject\RuleDefinition;

/**
 * @changelog https://wiki.php.net/rfc/final_promotion
 *
 * @see \Rector\Tests\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector\DowngradeFinalPropertyPromotionRectorTest
 */
final class DowngradeFinalPropertyPromotionRector extends AbstractRector
{
    /**
     * @var string
     */
    private const TAGNAME = 'final';

    public function __construct(
        private readonly VisibilityManipulator $visibilityManipulator,
        private readonly DocBlockUpdater $docBlockUpdater,
        private readonly PhpDocInfoFactory $phpDocInfoFactory,
    ) {
    }

    public function getRuleDefinition(): RuleDefinition
    {
        return new RuleDefinition('Change constructor final property promotion to @final annotation assign', [
            new CodeSample(
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function __construct(
        final public string $id
    ){}
}
CODE_SAMPLE

                ,
                <<<'CODE_SAMPLE'
class SomeClass
{
    public function __construct(
        /** @final */
        public string $id
    ) {}
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
        return [ClassMethod::class];
    }

    /**
     * @param ClassMethod $node
     */
    public function refactor(Node $node): null
    {

        if (! $this->isName($node, MethodName::CONSTRUCT)) {
            return null;
        }

        foreach ($node->params as $param) {
            if (! $param->isPromoted()) {
                continue;
            }
            if (! $this->visibilityManipulator->hasVisibility($param, Visibility::FINAL)) {
                continue;
            }

            $this->visibilityManipulator->makeNonFinal($param);

            $this->addPhpDocTag($param);

        }

        return null;
    }

    private function addPhpDocTag(Property|Param $node): bool
    {
        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($node);

        if ($phpDocInfo->hasByName(self::TAGNAME)) {
            return false;
        }

        $phpDocInfo->addPhpDocTagNode(new PhpDocTagNode('@' . self::TAGNAME, new GenericTagValueNode('')));
        $this->docBlockUpdater->updateRefactoredNodeWithPhpDocInfo($node);
        return true;
    }
}
