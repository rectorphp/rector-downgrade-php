<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

final class SkipInsideDefineCheck
{
    public function run($options)
    {
        if (\defined('WHATEVER')) {
            $options = $options & ~\JSON_THROW_ON_ERROR;
        }
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

final class SkipInsideDefineCheck
{
    public function run($options)
    {
        if (\defined('WHATEVER')) {
            $options = $options & ~0;
        }
    }
}

?>
