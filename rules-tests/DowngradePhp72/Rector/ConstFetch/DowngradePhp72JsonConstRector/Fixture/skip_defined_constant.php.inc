<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp72\Rector\ConstFetch\DowngradePhp72JsonConstRector\Fixture;

final class SkipDefinedConstant
{
    public function run($argument)
    {
        if (defined('JSON_INVALID_UTF8_IGNORE')) {
            return json_encode($argument, JSON_INVALID_UTF8_IGNORE);
        }

        return null;
    }
}
