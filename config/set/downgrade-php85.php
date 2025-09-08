<?php

declare(strict_types=1);

use Rector\Config\RectorConfig;
use Rector\DowngradePhp85\Rector\Class_\DowngradeFinalPropertyPromotionRector;
use Rector\DowngradePhp85\Rector\FuncCall\DowngradeArrayFirstLastRector;
use Rector\Renaming\Rector\ClassConstFetch\RenameClassConstFetchRector;
use Rector\Renaming\Rector\MethodCall\RenameMethodRector;
use Rector\Renaming\ValueObject\MethodCallRename;
use Rector\Renaming\ValueObject\RenameClassAndConstFetch;
use Rector\ValueObject\PhpVersion;

return static function (RectorConfig $rectorConfig): void {
    $rectorConfig->phpVersion(PhpVersion::PHP_84);
    $rectorConfig->rules([
        DowngradeArrayFirstLastRector::class,
        DowngradeFinalPropertyPromotionRector::class,
    ]);

    // https://wiki.php.net/rfc/deprecations_php_8_5#deprecate_driver_specific_pdo_constants_and_methods
    $rectorConfig->ruleWithConfiguration(
        RenameMethodRector::class,
        [
            new MethodCallRename('Pdo\Pgsql', 'copyFromArray', 'pgsqlCopyFromArray'),
            new MethodCallRename('Pdo\Pgsql', 'copyFromFile', 'pgsqlCopyFromFile'),
            new MethodCallRename('Pdo\Pgsql', 'copyToArray', 'pgsqlCopyToArray'),
            new MethodCallRename('Pdo\Pgsql', 'copyToFile', 'pgsqlCopyToFile'),
            new MethodCallRename('Pdo\Pgsql', 'getNotify', 'pgsqlGetNotify'),
            new MethodCallRename('Pdo\Pgsql', 'getPid', 'pgsqlGetPid'),
            new MethodCallRename('Pdo\Pgsql', 'lobCreate', 'pgsqlLOBCreate'),
            new MethodCallRename('Pdo\Pgsql', 'lobOpen', 'pgsqlLOBOpen'),
            new MethodCallRename('Pdo\Pgsql', 'lobUnlink', 'pgsqlLOBUnlink'),
            new MethodCallRename('Pdo\Sqlite', 'createAggregate', 'sqliteCreateAggregate'),
            new MethodCallRename('Pdo\Sqlite', 'createCollation', 'sqliteCreateCollation'),
            new MethodCallRename('Pdo\Sqlite', 'createFunction', 'sqliteCreateFunction'),
        ]
    );

    // https://wiki.php.net/rfc/deprecations_php_8_5#deprecate_driver_specific_pdo_constants_and_methods
    $rectorConfig->ruleWithConfiguration(
        RenameClassConstFetchRector::class,
        [
            new RenameClassAndConstFetch(
                'Pdo\Dblib',
                'ATTR_CONNECTION_TIMEOUT',
                'PDO',
                'DBLIB_ATTR_CONNECTION_TIMEOUT'
            ),
            new RenameClassAndConstFetch('Pdo\Dblib', 'ATTR_QUERY_TIMEOUT', 'PDO', 'DBLIB_ATTR_QUERY_TIMEOUT'),
            new RenameClassAndConstFetch(
                'Pdo\Dblib',
                'ATTR_STRINGIFY_UNIQUEIDENTIFIER',
                'PDO',
                'DBLIB_ATTR_STRINGIFY_UNIQUEIDENTIFIER'
            ),
            new RenameClassAndConstFetch('Pdo\Dblib', 'ATTR_VERSION', 'PDO', 'DBLIB_ATTR_VERSION'),
            new RenameClassAndConstFetch('Pdo\Dblib', 'ATTR_TDS_VERSION', 'PDO', 'DBLIB_ATTR_TDS_VERSION'),
            new RenameClassAndConstFetch(
                'Pdo\Dblib',
                'ATTR_SKIP_EMPTY_ROWSETS',
                'PDO',
                'DBLIB_ATTR_SKIP_EMPTY_ROWSETS'
            ),
            new RenameClassAndConstFetch('Pdo\Dblib', 'ATTR_DATETIME_CONVERT', 'PDO', 'DBLIB_ATTR_DATETIME_CONVERT'),
            new RenameClassAndConstFetch('Pdo\Firebird', 'ATTR_DATE_FORMAT', 'PDO', 'FB_ATTR_DATE_FORMAT'),
            new RenameClassAndConstFetch('Pdo\Firebird', 'ATTR_TIME_FORMAT', 'PDO', 'FB_ATTR_TIME_FORMAT', ),
            new RenameClassAndConstFetch('Pdo\Firebird', 'ATTR_TIMESTAMP_FORMAT', 'PDO', 'FB_ATTR_TIMESTAMP_FORMAT'),
            new RenameClassAndConstFetch(
                'Pdo\Mysql',
                'ATTR_USE_BUFFERED_QUERY',
                'PDO',
                'MYSQL_ATTR_USE_BUFFERED_QUERY'
            ),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_LOCAL_INFILE', 'PDO', 'MYSQL_ATTR_LOCAL_INFILE'),
            new RenameClassAndConstFetch(
                'Pdo\Mysql',
                'ATTR_LOCAL_INFILE_DIRECTORY',
                'PDO',
                'MYSQL_ATTR_LOCAL_INFILE_DIRECTORY'
            ),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_INIT_COMMAND', 'PDO', 'MYSQL_ATTR_INIT_COMMAND'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_MAX_BUFFER_SIZE', 'PDO', 'MYSQL_ATTR_MAX_BUFFER_SIZE'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_READ_DEFAULT_FILE', 'PDO', 'MYSQL_ATTR_READ_DEFAULT_FILE'),
            new RenameClassAndConstFetch(
                'Pdo\Mysql',
                'ATTR_READ_DEFAULT_GROUP',
                'PDO',
                'MYSQL_ATTR_READ_DEFAULT_GROUP'
            ),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_COMPRESS', 'PDO', 'MYSQL_ATTR_COMPRESS'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_DIRECT_QUERY', 'PDO', 'MYSQL_ATTR_DIRECT_QUERY'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_FOUND_ROWS', 'PDO', 'MYSQL_ATTR_FOUND_ROWS'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_IGNORE_SPACE', 'PDO', 'MYSQL_ATTR_IGNORE_SPACE'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SSL_KEY', 'PDO', 'MYSQL_ATTR_SSL_KEY'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SSL_CERT', 'PDO', 'MYSQL_ATTR_SSL_CERT'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SSL_CA', 'PDO', 'MYSQL_ATTR_SSL_CA'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SSL_CAPATH', 'PDO', 'MYSQL_ATTR_SSL_CAPATH'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SSL_CIPHER', 'PDO', 'MYSQL_ATTR_SSL_CIPHER'),
            new RenameClassAndConstFetch(
                'Pdo\Mysql',
                'ATTR_SSL_VERIFY_SERVER_CERT',
                'PDO',
                'MYSQL_ATTR_SSL_VERIFY_SERVER_CERT'
            ),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_SERVER_PUBLIC_KEY', 'PDO', 'MYSQL_ATTR_SERVER_PUBLIC_KEY'),
            new RenameClassAndConstFetch('Pdo\Mysql', 'ATTR_MULTI_STATEMENTS', 'PDO', 'MYSQL_ATTR_MULTI_STATEMENTS'),
            new RenameClassAndConstFetch('Pdo\Odbc', 'ATTR_USE_CURSOR_LIBRARY', 'PDO', 'ODBC_ATTR_USE_CURSOR_LIBRARY'),
            new RenameClassAndConstFetch('Pdo\Odbc', 'ATTR_ASSUME_UTF8', 'PDO', 'ODBC_ATTR_ASSUME_UTF8'),
            new RenameClassAndConstFetch('Pdo\Odbc', 'SQL_USE_IF_NEEDED', 'PDO', 'ODBC_SQL_USE_IF_NEEDED'),
            new RenameClassAndConstFetch('Pdo\Odbc', 'SQL_USE_DRIVER', 'PDO', 'ODBC_SQL_USE_DRIVER'),
            new RenameClassAndConstFetch('Pdo\Odbc', 'SQL_USE_ODBC', 'PDO', 'ODBC_SQL_USE_ODBC'),
            new RenameClassAndConstFetch('Pdo\Pgsql', 'ATTR_DISABLE_PREPARES', 'PDO', 'PGSQL_ATTR_DISABLE_PREPARES'),
            new RenameClassAndConstFetch(
                'Pdo\Sqlite',
                'ATTR_EXTENDED_RESULT_CODES',
                'PDO',
                'SQLITE_ATTR_EXTENDED_RESULT_CODES'
            ),
            new RenameClassAndConstFetch('Pdo\Sqlite', 'OPEN_FLAGS', 'PDO', 'SQLITE_ATTR_OPEN_FLAGS'),
            new RenameClassAndConstFetch(
                'Pdo\Sqlite',
                'ATTR_READONLY_STATEMENT',
                'PDO',
                'SQLITE_ATTR_READONLY_STATEMENT'
            ),
            new RenameClassAndConstFetch('Pdo\Sqlite', 'DETERMINISTIC', 'PDO', 'SQLITE_DETERMINISTIC'),
            new RenameClassAndConstFetch('Pdo\Sqlite', 'OPEN_READONLY', 'PDO', 'SQLITE_OPEN_READONLY'),
            new RenameClassAndConstFetch('Pdo\Sqlite', 'OPEN_READWRITE', 'PDO', 'SQLITE_OPEN_READWRITE'),
            new RenameClassAndConstFetch('Pdo\Sqlite', 'OPEN_CREATE', 'PDO', 'SQLITE_OPEN_CREATE'),
        ]
    );
};
