<?php

namespace Rector\Tests\Issues\DowngradeNullableInitialization\Fixture;

final class AddNullableInitializtion
{
    public function __construct(
        private array $doctrineTypeToScalarType = [
            'tinyint' => new \PHPStan\Type\BooleanType(),
        ]
     ) {}
}

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeNullableInitialization\Fixture;

final class AddNullableInitializtion
{
    private array $doctrineTypeToScalarType;
    public function __construct(?array $doctrineTypeToScalarType = null)
    {
        $this->doctrineTypeToScalarType = $doctrineTypeToScalarType ?? [
            'tinyint' => new \PHPStan\Type\BooleanType(),
        ];
        $this->doctrineTypeToScalarType = $doctrineTypeToScalarType;
    }
}

?>
