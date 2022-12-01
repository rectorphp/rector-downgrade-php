<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class NullCoalescingThrow
{
    public function run($type)
    {
        $result = 'some ' . ($type->type ?? throw new \InvalidArgumentException());
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class NullCoalescingThrow
{
    public function run($type)
    {
        if ($type->type === null) {
            throw new \InvalidArgumentException();
        }
        $result = 'some ' . ($type->type);
    }
}

?>
