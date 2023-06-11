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
        $delimiter = $delimiter === '(' ? ')' : ($delimiter === '{' ? '}' : ($delimiter === '[' ? ']' : ($delimiter === '<' ? '>' : $delimiter)));
    }
}

?>

