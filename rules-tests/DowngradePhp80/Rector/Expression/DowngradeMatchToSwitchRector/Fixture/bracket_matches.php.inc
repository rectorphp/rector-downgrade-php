<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class BracketMatches
{
    public function run($delimiter)
    {
        $delimiter = match ($delimiter) {
            '(' => ')',
            '{' => '}',
            '[' => ']',
            '<' => '>',
            default => $delimiter
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

final class BracketMatches
{
    public function run($delimiter)
    {
        switch ($delimiter) {
            case '(':
                $delimiter = ')';
                break;
            case '{':
                $delimiter = '}';
                break;
            case '[':
                $delimiter = ']';
                break;
            case '<':
                $delimiter = '>';
                break;
            default:
                $delimiter = $delimiter;
                break;
        }
    }
}

?>