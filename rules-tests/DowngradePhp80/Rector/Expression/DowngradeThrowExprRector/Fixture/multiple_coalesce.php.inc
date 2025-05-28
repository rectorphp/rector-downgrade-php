<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

class MultipleCoalesce
{
    public function run($content)
    {
        $contentId = $content->getInternalId() ?? $content->getId() ?? throw new \LogicException('content id is required for ackVersion');
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

class MultipleCoalesce
{
    public function run($content)
    {
        $contentId = $content->getInternalId() ?? $content->getId();
        if ($contentId === null) {
            throw new \LogicException('content id is required for ackVersion');
        }
    }
}

?>
