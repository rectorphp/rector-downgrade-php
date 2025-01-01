<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class SkipAlreadyHasObjectType
{
    function test(array|\Traversable $data) {
        $c = iterator_count(is_array($data) ? new \ArrayIterator($data) : $data);
        $v = iterator_to_array(is_array($data) ? new \ArrayIterator($data) : $data);
    }
}
