<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp83\Rector\ClassConst\DowngradeTypedClassConstRector;

class TypedClassConstant
{
    public const string FOO = 'foo';
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp83\Rector\ClassConst\DowngradeTypedClassConstRector;

class TypedClassConstant
{
    /**
     * @var string
     */
    public const FOO = 'foo';
}

?>
