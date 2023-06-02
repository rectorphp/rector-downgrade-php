<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

use PhpParser\Node\Expr\MethodCall;

class MethodCallAsArg2
{
    public function run(MethodCall $node)
    {
        $firstItemKey = array_key_first($node->getArgs());
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
        $getArgs = $node->getArgs();
        reset($getArgs);
        $firstItemKey = key($getArgs);
    }
}

?>
