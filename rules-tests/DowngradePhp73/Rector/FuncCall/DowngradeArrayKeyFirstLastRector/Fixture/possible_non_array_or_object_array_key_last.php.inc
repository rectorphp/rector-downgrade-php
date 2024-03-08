<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class PossibleNonArrayOrObjectArrayKeyLast
{
    protected mixed $value = null;

    private function run(): bool
    {
        $v = $this->value;

        if (!\is_array($v) || 1 !== \count($v) || 10 !== \strlen($k = (string) array_key_last($v)) || "\x9D" !== $k[0] || "\0" !== $k[5] || "\x5F" !== $k[9]) {
            return false;
        }

        return true;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class PossibleNonArrayOrObjectArrayKeyLast
{
    protected mixed $value = null;

    private function run(): bool
    {
        $v = $this->value;
        if (is_array($v)) {
            end($v);
        }

        if (!\is_array($v) || 1 !== \count($v) || 10 !== \strlen($k = (string) key($v)) || "\x9D" !== $k[0] || "\0" !== $k[5] || "\x5F" !== $k[9]) {
            reset($v);
            return false;
        }

        return true;
    }
}

?>
