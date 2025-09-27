<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class WithNamedArg
{
    function test(array|\Traversable $data) {
        $v = iterator_to_array(preserve_keys: false, iterator: $data);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class WithNamedArg
{
    function test(array|\Traversable $data) {
        $v = iterator_to_array(preserve_keys: false, iterator: is_array($data) ? new \ArrayIterator($data) : $data);
    }
}

?>
