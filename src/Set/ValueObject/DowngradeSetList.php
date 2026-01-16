<?php

declare(strict_types=1);

namespace Rector\Set\ValueObject;

/**
 * @api
 * @deprecated use ->withDowngradeSets() in rector.php instead
 */
final class DowngradeSetList
{
    public const string PHP_72 = __DIR__ . '/../../../config/set/downgrade-php72.php';

    public const string PHP_73 = __DIR__ . '/../../../config/set/downgrade-php73.php';

    public const string PHP_74 = __DIR__ . '/../../../config/set/downgrade-php74.php';

    public const string PHP_80 = __DIR__ . '/../../../config/set/downgrade-php80.php';

    public const string PHP_81 = __DIR__ . '/../../../config/set/downgrade-php81.php';

    public const string PHP_82 = __DIR__ . '/../../../config/set/downgrade-php82.php';

    public const string PHP_83 = __DIR__ . '/../../../config/set/downgrade-php83.php';

    public const string PHP_84 = __DIR__ . '/../../../config/set/downgrade-php84.php';

    public const string PHP_85 = __DIR__ . '/../../../config/set/downgrade-php85.php';
}
