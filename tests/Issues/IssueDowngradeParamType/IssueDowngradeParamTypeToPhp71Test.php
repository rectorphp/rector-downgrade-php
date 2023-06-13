<?php

declare(strict_types=1);

namespace Rector\Tests\IssueseDowngradeParamType;

use Iterator;
use PHPUnit\Framework\Attributes\DataProvider;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class IssueDowngradeParamTypeToPhp71Test extends AbstractRectorTestCase
{
    #[DataProvider('provideData')]
    public function test(string $filePath): void
    {
        $this->doTestFile($filePath);
    }

    public static function provideData(): Iterator
    {
        return self::yieldFilesFromDirectory(__DIR__ . '/FixtureDownToPhp71');
    }

    public function provideConfigFilePath(): string
    {
        return __DIR__ . '/config/configured_rule_downgrade_down_to_php71.php';
    }
}
