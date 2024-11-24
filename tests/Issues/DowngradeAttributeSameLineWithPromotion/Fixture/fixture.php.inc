<?php

namespace Rector\Tests\Issues\DowngradeAttributeSameLineWithPromotion\Fixture;

#[\Attribute]final class WithSameLine
{
    public function __construct(public string $a)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeAttributeSameLineWithPromotion\Fixture;

#[\Attribute]
final class WithSameLine
{
    public string $a;
    public function __construct(string $a)
    {
        $this->a = $a;
    }
}

?>
