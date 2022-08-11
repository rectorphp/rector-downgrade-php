<?php

namespace Rector\Tests\DowngradePhp71\Rector\FunctionLike\DowngradeNullableTypeDeclarationRector\Fixture;

final class ReturnType
{
    public function run(): ?string
    {
        if (mt_rand()) {
            return null;
        }

        return 'value';
    }
}

?>
