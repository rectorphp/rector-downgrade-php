<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class HeredocMessage
{
    #[\Deprecated(message: <<<'TXT'
    Niche mechanism, no longer applied. Let Rector handle cache on its own.
     If custom invalidation is needed, handle it in CI.
    TXT)]
    public function someMethod(): void
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp84\Rector\ClassMethod\DowngradeDeprecatedAttributeRector\Fixture;

class HeredocMessage
{
    /**
     * @deprecated Niche mechanism, no longer applied. Let Rector handle cache on its own. If custom invalidation is needed, handle it in CI.
     */
    public function someMethod(): void
    {
    }
}

?>
