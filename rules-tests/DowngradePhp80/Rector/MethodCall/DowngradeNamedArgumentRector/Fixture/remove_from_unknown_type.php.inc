<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Fixture;

final class RemoveFromUnknownType
{
    function someMethod($container, $abstract, $parameters ) {
        return $container->resolve($abstract, $parameters, raiseEvents: \true);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeNamedArgumentRector\Fixture;

final class RemoveFromUnknownType
{
    function someMethod($container, $abstract, $parameters ) {
        return $container->resolve($abstract, $parameters, \true);
    }
}

?>
