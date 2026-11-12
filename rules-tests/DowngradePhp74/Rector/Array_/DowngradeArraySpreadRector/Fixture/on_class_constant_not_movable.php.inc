<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ParentWithRelativeConstant;

final class OnClassConstantNotMovable extends ParentWithRelativeConstant
{
    public const A = 'child-a';

    private const USES_SELF_INHERITED = [...self::USES_SELF];

    private const USES_MAGIC_INHERITED = [...self::USES_MAGIC];

    private const USES_NAMESPACED_CONSTANT_INHERITED = [...self::USES_NAMESPACED_CONSTANT];

    private const USES_PRIVATE_BY_NAME_INHERITED = [...self::USES_PRIVATE_BY_NAME];
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Source\ParentWithRelativeConstant;

final class OnClassConstantNotMovable extends ParentWithRelativeConstant
{
    public const A = 'child-a';

    private const USES_SELF_INHERITED = array_merge(self::USES_SELF);

    private const USES_MAGIC_INHERITED = array_merge(self::USES_MAGIC);

    private const USES_NAMESPACED_CONSTANT_INHERITED = array_merge(self::USES_NAMESPACED_CONSTANT);

    private const USES_PRIVATE_BY_NAME_INHERITED = array_merge(self::USES_PRIVATE_BY_NAME);
}

?>
