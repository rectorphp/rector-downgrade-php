<?php

namespace Rector\Tests\DowngradePhp80\Rector\MethodCall\DowngradeReflectionGetAttributesRector\Fixture;

final class DemoFile
{
    public function run($function_name)
    {
        $reflection_handler = new ReflectionFunction($function_name);
        foreach ( $reflection_handler->getParameters() as $arg ) {
            if (
				        class_exists( SensitiveParameter::class, false ) &&
				        method_exists( $arg, 'getAttributes' ) &&
				        $arg->getAttributes( SensitiveParameter::class ) !== array()
            ) {
                echo "hello";
            }
        }
    }
}
?>
