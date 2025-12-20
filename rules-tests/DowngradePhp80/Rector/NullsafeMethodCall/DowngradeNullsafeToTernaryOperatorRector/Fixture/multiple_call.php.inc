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
        $result = ($nullsafeVariable1 = ($nullsafeVariable3 = $object->multiple($args1)) ? $nullsafeVariable3->call($args2) : null) ? $nullsafeVariable1->otherCall($args3) : null;
        $result = ($nullsafeVariable2 = ($nullsafeVariable4 = ($nullsafeVariable5 = $object->multiple($args1)) ? $nullsafeVariable5->call($args2) : null) ? $nullsafeVariable4->otherCall($args3) : null) ? $nullsafeVariable2->anotherCall($args4) : null;
    }
}

?>
