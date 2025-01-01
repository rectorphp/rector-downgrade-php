<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class SkipInternary
{
    public function run($taggedServices)
    {
        return \is_array($taggedServices) ? $taggedServices : \iterator_to_array($taggedServices);
    }
}
