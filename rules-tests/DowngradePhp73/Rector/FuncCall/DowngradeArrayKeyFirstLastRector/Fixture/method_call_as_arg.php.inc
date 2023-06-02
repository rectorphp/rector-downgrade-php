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
        $args = $node->getArgs();
        end($args);
        $lastItemKey = array_key_last($args);
    }
}

?>
