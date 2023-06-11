<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class InArrowFunctionInExpression
{
    public function run($value)
    {
        static fn (mixed $default): mixed => match (true) {
                is_string($default) => sprintf('"%s"', $default),
                default => $default,
            };
    }
}

?>
