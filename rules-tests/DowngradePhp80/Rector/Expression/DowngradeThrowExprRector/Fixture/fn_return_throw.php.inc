<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

class FnReturnThrow
{
    public function run()
    {
        $line = Callback::invokeSafe('fgets', [$f], fn($error) => throw new Nette\IOException(\sprintf("Unable to read file '%s'. %s", self::normalizePath($file), $error)));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

class FnReturnThrow
{
    public function run()
    {
        $line = Callback::invokeSafe('fgets', [$f], function ($error) use ($file) {
            throw new Nette\IOException(\sprintf("Unable to read file '%s'. %s", self::normalizePath($file), $error));
        });
    }
}

?>
