<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp85\Rector\StmtsAwareInterface\DowngradePipeOperatorRector;

use Iterator;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\RequiresPhp;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class DowngradePipeOperatorRectorTest extends AbstractRectorTestCase
{
    #[DataProvider('provideData')]
    #[RequiresPhp('>= 8.5')]
    public function test(string $filePath): void
    {
        $this->doTestFile($filePath);
    }

    public static function provideData(): Iterator
    {
        return self::yieldFilesFromDirectory(__DIR__ . '/Fixture');
    }

    public function provideConfigFilePath(): string
    {
        return __DIR__ . '/config/configured_rule.php';
    }
}
