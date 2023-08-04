<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

use PhpParser\Node\Expr\ArrayItem;
final class GetNullable
{
    public function run($value)
    {
        return $this->extractArrayItemByKey($value)?->value;
    }

    protected function extractArrayItemByKey($value): ?ArrayItem
    {
        return null;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

use PhpParser\Node\Expr\ArrayItem;
final class GetNullable
{
    public function run($value)
    {
        return ($nullsafeVariable6 = $this->extractArrayItemByKey($value)) ? $nullsafeVariable6->value : null;
    }

    protected function extractArrayItemByKey($value): ?ArrayItem
    {
        return null;
    }
}

?>
