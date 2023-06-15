<?php

namespace Rector\Tests\DowngradePhp72\Rector\ClassMethod\DowngradeParameterTypeWideningRector\Fixture;

class DefaultNullNotPartOfUnion
{
    /**
     *
     * @param int|string|array|null $children
     */
    public function addDefaultChildrenIfNoneSet(int|string|array $children = null)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp72\Rector\ClassMethod\DowngradeParameterTypeWideningRector\Fixture;

class DefaultNullNotPartOfUnion
{
    /**
     *
     * @param int|string|array|null $children
     */
    public function addDefaultChildrenIfNoneSet($children = null)
    {
    }
}

?>
