<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class InArrowFunction
{
    public function run()
    {
        $defaults = [
            'foo' => 'first is foo',
            'bar' => 'second is bar',
        ];

        $mapped = array_map(
            static fn (mixed $default): mixed => match (true) {
                is_string($default) => sprintf('"%s"', $default),
                default => $default,
            }, $defaults
        );

        return $mapped;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class InArrowFunction
{
    public function run()
    {
        $defaults = [
            'foo' => 'first is foo',
            'bar' => 'second is bar',
        ];

        $mapped = array_map(
            static fn (mixed $default): mixed => true === is_string($default) ? sprintf('"%s"', $default) : $default, $defaults
        );

        return $mapped;
    }
}

?>
