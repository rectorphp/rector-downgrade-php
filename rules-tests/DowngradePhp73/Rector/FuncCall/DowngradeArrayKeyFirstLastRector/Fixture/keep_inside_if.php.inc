<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class KeepInsideIf
{
    public function run($argumentValue)
    {
        // from Symfony 6.2
        if (\is_array($argumentValue)) {
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
        // from Symfony 6.2
        if (\is_array($argumentValue)) {
            end($argumentValue);
            $this->completionValue = $argumentValue ? $argumentValue[key($argumentValue)] : null;
        }
    }
}

?>
