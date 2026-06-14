<?php

namespace Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Fixture;

use Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Source\SomeChildAware;

class SkipNonDomObject
{
    public function run(SomeChildAware $someChildAware)
    {
        foreach ($someChildAware->childNodes as $childNode) {
            echo $childNode;
        }
    }
}
