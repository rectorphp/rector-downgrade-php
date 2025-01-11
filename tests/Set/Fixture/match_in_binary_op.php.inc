<?php

namespace Rector\Tests\Set\Fixture;

final class MatchInBinaryOp
{
    public function run($value, $booleanFlag)
    {
        return match (true) {
            $value === 2 => true,
            default => false,
        } && $booleanFlag;
    }

    public function runTwo($value, $booleanFlag)
    {
        return match (true) {
                $value === 2 => true,
                default => false,
        } || $booleanFlag;
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class MatchInBinaryOp
{
    public function run($value, $booleanFlag)
    {
        switch (true) {
            case $value === 2:
                return true && $booleanFlag;
            default:
                return false && $booleanFlag;
        }
    }

    public function runTwo($value, $booleanFlag)
    {
        switch (true) {
            case $value === 2:
                return true || $booleanFlag;
            default:
                return false || $booleanFlag;
        }
    }
}

?>
