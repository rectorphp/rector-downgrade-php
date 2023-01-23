<?php

namespace Rector\Tests\DowngradePhp73\Rector\String_\DowngradeFlexibleHeredocSyntaxRector\Fixture;

class LineEndsWithNewlineOrSemicolon
{
    public function run()
    {
        $good1 = <<<EOS
test
EOS;

        $good2 = <<<EOS
test
EOS
;

        $needsDowngrade1 = sprintf(<<<EOS
test %s
EOS, 'more');

        $needsDowngrade2 = <<<EOS
test
EOS; $z = '';
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\String_\DowngradeFlexibleHeredocSyntaxRector\Fixture;

class LineEndsWithNewlineOrSemicolon
{
    public function run()
    {
        $good1 = <<<EOS
test
EOS;

        $good2 = <<<EOS
test
EOS
;

        $needsDowngrade1 = sprintf(<<<EOS
test %s
EOS
, 'more');

        $needsDowngrade2 = <<<EOS
test
EOS
; $z = '';
    }
}

?>
