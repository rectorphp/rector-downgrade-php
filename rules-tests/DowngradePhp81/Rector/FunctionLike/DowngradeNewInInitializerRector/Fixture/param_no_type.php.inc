<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class ParamNoType
{
    public function __construct(public $o1 = new stdClass)
    {
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

final class ParamNoType
{
    public function __construct(public $o1 = null)
    {
        $this->o1 = $o1 ?? new stdClass;
    }
}

?>
