<?php

namespace Rector\Tests\Set\Fixture;

use InvalidArgumentException;

final class MatchAndThrowExpr
{
    public function run($value)
    {
        return match ($value) {
            1 => 'one',
            2 => 'two',
            default => throw new InvalidArgumentException()
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

use InvalidArgumentException;

final class MatchAndThrowExpr
{
    public function run($value)
    {
        switch ($value) {
            case 1:
                return 'one';
            case 2:
                return 'two';
            default:
                throw new InvalidArgumentException();
        }
    }
}

?>
