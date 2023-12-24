<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class MatchAsArg
{
    public function run($param)
    {
        return execute(
            match ($param) {
                true => 1,
                false => new \stdClass(),
            },
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class MatchAsArg
{
    public function run($param)
    {
        return execute(
            (function () use ($param) {
                switch ($param) {
                    case true:
                        return 1;
                    case false:
                        return new \stdClass();
                }
            })(),
        );
    }
}

?>
