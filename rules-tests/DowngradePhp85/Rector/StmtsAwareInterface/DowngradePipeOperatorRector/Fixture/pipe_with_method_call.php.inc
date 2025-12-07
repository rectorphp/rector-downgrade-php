<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

class StringProcessor {
    public function process($str) {
        return trim($str);
    }
}

$processor = new StringProcessor();
$result = "  hello  " |> $processor->process(...);

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector\Fixture;

class StringProcessor {
    public function process($str) {
        return trim($str);
    }
}

$processor = new StringProcessor();
$result = $processor->process("  hello  ");

?>