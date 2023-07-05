<?php

namespace Rector\Tests\Issues\IssueDowngradeUnionTypeAndParameterTypeWideningWithConfiguration\Fixture;

class ParentClass
{
    public function import(bool $ignoreErrors = false, string $sourceResource = null, string|array $exclude = null)
    {
    }
}

class ChildClass extends ParentClass
{
    public function import(bool|string $ignoreErrors = false, string $sourceResource = null, $exclude = null): mixed
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\Issues\IssueDowngradeUnionTypeAndParameterTypeWideningWithConfiguration\Fixture;

class ParentClass
{
    public function import($ignoreErrors = false, string $sourceResource = null, $exclude = null)
    {
    }
}

class ChildClass extends ParentClass
{
    public function import($ignoreErrors = false, string $sourceResource = null, $exclude = null): mixed
    {
    }
}

?>
