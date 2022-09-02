<?php

declare(strict_types=1);

namespace Rector\Tests\DowngradePhp72\Rector\ClassMethod\DowngradeParameterTypeWideningRector;

use Iterator;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;

final class EmptyConfigTest extends AbstractRectorTestCase
{
    /**
     * @dataProvider provideData()
     */
    public function test(string $filePath): void
    {
        $this->doTestFile($filePath);
    }

    public function provideData(): Iterator
    {
        return $this->yieldFilesFromDirectory(__DIR__ . '/FixtureEmptyConfig');
    }

    public function provideConfigFilePath(): string
    {
        return __DIR__ . '/config/empty_config.php';
    }
}
