<?php

namespace Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Fixture;

class SkipAlreadyCoalesced
{
    public function run(\DOMNode $node)
    {
        foreach ($node->childNodes ?? [] as $childNode) {
            echo $childNode->nodeValue;
        }
    }
}
