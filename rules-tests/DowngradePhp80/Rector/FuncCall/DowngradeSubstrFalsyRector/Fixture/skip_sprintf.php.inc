<?php
namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeSubstrFalsyRector\Fixture;

/**
 * sprintf %s format converts false to empty string
 */
class SkipSprintf
{
    public function run(string $name)
    {
        return sprintf('Value: %s', substr($name, 2));
    }

    public function run2(string $name)
    {
        printf('Value: %s', substr($name, 2));
    }
}