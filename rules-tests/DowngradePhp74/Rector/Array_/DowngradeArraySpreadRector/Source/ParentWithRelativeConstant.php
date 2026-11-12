<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source;

const NAMESPACED_CONSTANT = 'namespaced';

class ParentWithRelativeConstant
{
    public const A = 'parent-a';

    public const USES_SELF = [self::A];

    public const USES_MAGIC = [__CLASS__];

    public const USES_NAMESPACED_CONSTANT = [NAMESPACED_CONSTANT];

    public const USES_PRIVATE_BY_NAME = [ParentWithRelativeConstant::HIDDEN];

    private const HIDDEN = 'hidden';
}
