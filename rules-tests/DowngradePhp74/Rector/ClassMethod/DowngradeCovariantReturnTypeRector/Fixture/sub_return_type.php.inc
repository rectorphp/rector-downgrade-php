<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\Handler;
use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\TempResponse;

/**
 * @extends Handler<TempResponse>
 */
final class SubReturnType extends Handler
{
    protected function set(): TempResponse {
        return new TempResponse();
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Fixture;

use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\Handler;
use Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\TempResponse;

/**
 * @extends Handler<TempResponse>
 */
final class SubReturnType extends Handler
{
    protected function set(): \Rector\Tests\DowngradePhp74\Rector\ClassMethod\DowngradeCovariantReturnTypeRector\Source\ResponseInterface {
        return new TempResponse();
    }
}

?>
