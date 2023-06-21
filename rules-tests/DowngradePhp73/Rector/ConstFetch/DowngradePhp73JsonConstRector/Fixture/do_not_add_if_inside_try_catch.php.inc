<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

final class DoNotAddIfInsideTryCatch
{
    public function run($resource)
    {
        try {
            $resource = \json_encode($resource, \JSON_THROW_ON_ERROR);
        } catch (\JsonException $exception) {
            $resource = \sprintf('resource of type "%s"', \get_debug_type($resource));
        }
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

final class DoNotAddIfInsideTryCatch
{
    public function run($resource)
    {
        try {
            $resource = \json_encode($resource, 0);
        } catch (\JsonException $exception) {
            $resource = \sprintf('resource of type "%s"', \get_debug_type($resource));
        }
    }
}

?>
