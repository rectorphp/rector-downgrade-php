<?php

namespace Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Fixture;

class SkipOtherProperty
{
    public function run(\DOMElement $element)
    {
        foreach ($element->attributes as $attribute) {
            echo $attribute->nodeValue;
        }
    }
}
