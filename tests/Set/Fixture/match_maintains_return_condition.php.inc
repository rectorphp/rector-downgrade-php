<?php

namespace Rector\Tests\Set\Fixture;

final class MatchBoolean
{
    public function run($value, $booleanFlag)
    {
        return match (true) {
            $value === 2 => true,
            default => false,
        } && $booleanFlag;
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class MatchBoolean
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
}

?>
