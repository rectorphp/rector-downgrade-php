<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class IsArrayGuardOnOtherExpr
{
    public function run($data, $other)
    {
        return is_array($other) ? $other : iterator_to_array($data);
    }

    public function run2($data)
    {
        return is_array($data) ? iterator_to_array($data) : [];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class IsArrayGuardOnOtherExpr
{
    public function run($data, $other)
    {
        return is_array($other) ? $other : iterator_to_array(is_array($data) ? new \ArrayIterator($data) : $data);
    }

    public function run2($data)
    {
        return is_array($data) ? iterator_to_array(is_array($data) ? new \ArrayIterator($data) : $data) : [];
    }
}

?>
