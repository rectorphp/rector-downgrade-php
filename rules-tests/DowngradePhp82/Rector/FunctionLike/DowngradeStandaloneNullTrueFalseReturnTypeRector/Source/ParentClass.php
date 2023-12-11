<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp82\Rector\FunctionLike\DowngradeStandaloneNullTrueFalseReturnTypeRector\Source;

class ParentClass
{
    public function getSomeString(): ?string
    {
        return 'test';
    }
}
