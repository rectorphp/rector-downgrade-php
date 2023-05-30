<?php

namespace Rector\Tests\DowngradePhp72\Rector\FuncCall\DowngradePregUnmatchedAsNullConstantRector\Fixture;

final class ComplexInIfDirectCall
{
    public function run($regexp)
    {
        try {
            if (preg_match_all($regexp, $this->string, $matches, $flags | \PREG_UNMATCHED_AS_NULL, $offset)) {
            }
        } catch (\Exception $e) {

        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp72\Rector\FuncCall\DowngradePregUnmatchedAsNullConstantRector\Fixture;

final class ComplexInIfDirectCall
{
    public function run($regexp)
    {
        try {
            if (preg_match_all($regexp, $this->string, $matches, $flags, $offset)) {
                array_walk_recursive($matches, function (&$value) {
                    if ($value === '') {
                        $value = null;
                    }
                });
            }
        } catch (\Exception $e) {

        }
    }
}

?>
