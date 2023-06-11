<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class TrueSubjectExpression
{
    public function run($statusCode)
    {
        $result = match (true) {
            ($statusCode >= 200 && $statusCode < 300) => 'success',
            in_array($statusCode, range(400, 499)) => 'client error',
            default => 'unknown status code',
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class TrueSubjectExpression
{
    public function run($statusCode)
    {
        $result = true === ($statusCode >= 200 && $statusCode < 300) ? 'success' : (true === in_array($statusCode, range(400, 499)) ? 'client error' : 'unknown status code');
    }
}

?>
