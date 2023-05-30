<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class KeepInsideIf
{
    public function run($argumentValue)
    {
        if (\is_array($argumentValue)) {
            $skipIt = true;
        } else {
            $this->completionValue = $argumentValue ? $argumentValue[array_key_last($argumentValue)] : null;
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class KeepInsideIf
{
    public function run($argumentValue)
    {
        if (\is_array($argumentValue)) {
            $skipIt = true;
        } else {
            end($argumentValue);
            $this->completionValue = $argumentValue ? $argumentValue[key($argumentValue)] : null;
        }
    }
}

?>
