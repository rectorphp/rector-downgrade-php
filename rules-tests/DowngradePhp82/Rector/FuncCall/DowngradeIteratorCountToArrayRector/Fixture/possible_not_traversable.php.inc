<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class PossibleNotTraversable
{
    function test(array|\Traversable $data) {
        $c = iterator_count($data);
        $v = iterator_to_array($data);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class PossibleNotTraversable
{
    function test(array|\Traversable $data) {
        $c = iterator_count(is_array($data) ? new \ArrayIterator($data) : $data);
        $v = iterator_to_array(is_array($data) ? new \ArrayIterator($data) : $data);
    }
}

?>
