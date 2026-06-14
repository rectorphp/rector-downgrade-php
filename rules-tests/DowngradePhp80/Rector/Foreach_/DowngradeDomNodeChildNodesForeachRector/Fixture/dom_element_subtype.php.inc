<?php

namespace Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Fixture;

class DomElementSubtype
{
    public function run(\DOMElement $element)
    {
        foreach ($element->childNodes as $childNode) {
            echo $childNode->nodeValue;
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Foreach_\DowngradeDomNodeChildNodesForeachRector\Fixture;

class DomElementSubtype
{
    public function run(\DOMElement $element)
    {
        foreach ($element->childNodes ?? [] as $childNode) {
            echo $childNode->nodeValue;
        }
    }
}

?>
