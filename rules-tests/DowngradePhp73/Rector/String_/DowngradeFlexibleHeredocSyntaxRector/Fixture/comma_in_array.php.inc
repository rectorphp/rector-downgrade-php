<?php

namespace Rector\Tests\DowngradePhp73\Rector\String_\DowngradeFlexibleHeredocSyntaxRector\Fixture;

class CommaInArray
{
    public function run()
    {
        $variable = [
                <<<EOT
                <?php
                /** @readonly */
                class C {
                }\n
            EOT,
            new \stdClass()
        ];
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\String_\DowngradeFlexibleHeredocSyntaxRector\Fixture;

class CommaInArray
{
    public function run()
    {
        $variable = [
                <<<EOT
<?php
/** @readonly */
class C {
}

EOT
,
            new \stdClass()
        ];
    }
}

?>
