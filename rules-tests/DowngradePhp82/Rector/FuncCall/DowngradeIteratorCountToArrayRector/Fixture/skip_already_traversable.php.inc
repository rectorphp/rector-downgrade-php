<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class SkipAlreadyTraversable
{
    function test(\Traversable $data)
    {
        $c = iterator_count($data);
        $v = iterator_to_array($data);
    }
}
