<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

use PhpParser\Node\Expr\MethodCall;

class MethodCallAsArg2
{
    public function run(MethodCall $node)
    {
        $lastItemKey = array_key_first($node->getArgs());
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

use PhpParser\Node\Expr\MethodCall;

class MethodCallAsArg2
{
    public function run(MethodCall $node)
    {
        $args = $node->getArgs();
        reset($args);
        $lastItemKey = key($args);
    }
}

?>
