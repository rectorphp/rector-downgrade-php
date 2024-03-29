<?php

namespace Rector\Tests\DowngradePhp72\Rector\FuncCall\DowngradePregUnmatchedAsNullConstantRector\Fixture;

final class DynamicName
{
    public function run()
    {
        $match = (\PREG_PATTERN_ORDER | \PREG_SET_ORDER) & $flags ? 'preg_match_all' : 'preg_match';
        try {
            if (\false === $match($regexp, $this->string, $matches, $flags | \PREG_UNMATCHED_AS_NULL, $offset)) {
            }
        } catch (\Exception $e) {

        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp72\Rector\FuncCall\DowngradePregUnmatchedAsNullConstantRector\Fixture;

final class DynamicName
{
    public function run()
    {
        $match = (\PREG_PATTERN_ORDER | \PREG_SET_ORDER) & $flags ? 'preg_match_all' : 'preg_match';
        try {
            if (\false === $match($regexp, $this->string, $matches, $flags, $offset)) {
            }
            array_walk_recursive($matches, function (&$value) {
                if ($value === '') {
                    $value = null;
                }
            });
        } catch (\Exception $e) {

        }
    }
}

?>
