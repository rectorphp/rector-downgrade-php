<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

class IterableA
{
    public function covariantReturnTypes(): iterable
    { /* … */ }
}

class IterableB extends IterableA
{
    public function covariantReturnTypes(): array
    { /* … */ }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

class IterableA
{
    public function covariantReturnTypes(): iterable
    { /* … */ }
}

class IterableB extends IterableA
{
    /**
     * @return mixed[]
     */
    public function covariantReturnTypes(): iterable
    { /* … */ }
}

?>
