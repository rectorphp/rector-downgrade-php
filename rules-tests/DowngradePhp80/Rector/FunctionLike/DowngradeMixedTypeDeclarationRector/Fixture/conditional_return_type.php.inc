<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeMixedTypeDeclarationRector\Fixture;

class ConditionalReturnType
{
    /**
     * @template TValue of array<array|scalar>|scalar
     *
     * @return (TValue is scalar ? array|scalar : array<array|scalar>)
     */
    public function resolveValue(): mixed
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FunctionLike\DowngradeMixedTypeDeclarationRector\Fixture;

class ConditionalReturnType
{
    /**
     * @template TValue of array<array|scalar>|scalar
     *
     * @return (TValue is scalar ? array|scalar : array<array|scalar>)
     */
    public function resolveValue()
    {
    }
}

?>
