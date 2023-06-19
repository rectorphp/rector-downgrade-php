<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

class InBitwise
{
    public function run($argument)
    {
        $argument = json_encode($argument, JSON_UNESCAPED_SLASHES | JSON_THROW_ON_ERROR);
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

class InBitwise
{
    public function run($argument)
    {
        $argument = json_encode($argument, JSON_UNESCAPED_SLASHES);
        if (json_last_error() !== JSON_ERROR_NONE) {
            throw new \Exception(json_last_error_msg());
        }
    }
}

?>
