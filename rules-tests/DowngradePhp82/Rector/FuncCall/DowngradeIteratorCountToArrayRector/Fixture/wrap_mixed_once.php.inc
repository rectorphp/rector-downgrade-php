<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class WrapMixedOnce
{
    public function run($data)
    {
        return iterator_to_array($data);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class WrapMixedOnce
{
    public function run($data)
    {
        return iterator_to_array(is_array($data) ? new \ArrayIterator($data) : $data);
    }
}

?>
