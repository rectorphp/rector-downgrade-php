<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class KeepInsideIfFirst
{
    public function run($argumentValue)
    {
        // from Symfony 6.2
        if (\is_array($argumentValue)) {
            $this->completionValue = $argumentValue ? $argumentValue[array_key_first($argumentValue)] : null;
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

final class KeepInsideIfFirst
{
    public function run($argumentValue)
    {
        // from Symfony 6.2
        if (\is_array($argumentValue)) {
            reset($argumentValue);
            $this->completionValue = $argumentValue ? $argumentValue[key($argumentValue)] : null;
        }
    }
}

?>
