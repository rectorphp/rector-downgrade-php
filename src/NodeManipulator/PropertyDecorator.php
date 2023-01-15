<?php

declare(strict_types=1);

namespace Rector\NodeManipulator;

use PhpParser\Node\ComplexType;
use PhpParser\Node\Identifier;
use PhpParser\Node\Name;
use PhpParser\Node\Stmt\Property;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfoFactory;
use Rector\BetterPhpDocParser\PhpDocManipulator\PhpDocTypeChanger;
use Rector\StaticTypeMapper\StaticTypeMapper;

final class PropertyDecorator
{
    public function __construct(
        private readonly PhpDocInfoFactory $phpDocInfoFactory,
        private readonly StaticTypeMapper $staticTypeMapper,
        private readonly PhpDocTypeChanger $phpDocTypeChanger,
    ) {
    }

    public function decorateWithDocBlock(Property $property, ComplexType|Identifier|Name $typeNode): void
    {
        $phpDocInfo = $this->phpDocInfoFactory->createFromNodeOrEmpty($property);
        if ($phpDocInfo->getVarTagValueNode() !== null) {
            return;
        }

        $newType = $this->staticTypeMapper->mapPhpParserNodePHPStanType($typeNode);
        $this->phpDocTypeChanger->changeVarType($phpDocInfo, $newType);
    }
}
