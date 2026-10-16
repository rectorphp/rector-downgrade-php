<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

final class SuperglobalsInArrowFunction
{
    public function usingServer()
    {
        PostStringyKey::retrieved(fn ($model) => $_SERVER['destroy']['retrieved'][] = $model->my_id);
    }
}
?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

final class SuperglobalsInArrowFunction
{
    public function usingServer()
    {
        PostStringyKey::retrieved(function ($model) {
            return $_SERVER['destroy']['retrieved'][] = $model->my_id;
        });
    }
}
?>
