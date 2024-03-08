<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

use PhpParser\Node\Expr\MethodCall;

class MethodCallAsArg
{
    public function run(MethodCall $node)
    {
        $lastItemKey = array_key_last($node->getArgs());
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

use PhpParser\Node\Expr\MethodCall;

class MethodCallAsArg
{
    public function run(MethodCall $node)
    {
        $getArgs = $node->getArgs();
        end($getArgs);
        $lastItemKey = key($getArgs);
        reset($getArgs);
    }
}

?>
