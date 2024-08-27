<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

interface MyInterface {
    public function myMethod(\stdClass $my_instance = new \stdClass());
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp81\Rector\FunctionLike\DowngradeNewInInitializerRector\Fixture;

interface MyInterface {
    public function myMethod(\stdClass $my_instance = null);
}

?>
