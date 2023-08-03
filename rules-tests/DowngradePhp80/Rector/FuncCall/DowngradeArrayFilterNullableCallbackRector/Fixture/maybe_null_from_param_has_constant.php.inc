<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeArrayFilterNullableCallbackRector\Fixture;

class MayBeNullFromParamHasConstant
{
    public function run(array $data, $callback = null)
    {
        var_dump(array_filter($data, $callback, ARRAY_FILTER_USE_KEY));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeArrayFilterNullableCallbackRector\Fixture;

class MayBeNullFromParamHasConstant
{
    public function run(array $data, $callback = null)
    {
        var_dump(array_filter($data, $callback === null ? fn($value, $key): bool => !empty($value) : $callback, $callback === null ? ARRAY_FILTER_USE_BOTH : ARRAY_FILTER_USE_KEY));
    }
}

?>
