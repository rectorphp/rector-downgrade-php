<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

class MultipleCall
{
    public function run($object)
    {
        $result = $object->multiple($args1)?->call($args2)?->otherCall($args3);
        $result = $object->multiple($args1)?->call($args2)?->otherCall($args3)?->anotherCall($args4);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

class MultipleCall
{
    public function run($object)
    {
        $result = ($nullsafeVariable8 = ($nullsafeVariable10 = $object->multiple($args1)) ? $nullsafeVariable10->call($args2) : null) ? $nullsafeVariable8->otherCall($args3) : null;
        $result = ($nullsafeVariable9 = ($nullsafeVariable11 = ($nullsafeVariable12 = $object->multiple($args1)) ? $nullsafeVariable12->call($args2) : null) ? $nullsafeVariable11->otherCall($args3) : null) ? $nullsafeVariable9->anotherCall($args4) : null;
    }
}

?>
