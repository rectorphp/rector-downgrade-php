<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeArrayFilterNullableCallbackRector\Fixture;

class MayBeNullFromParam
{
    public function run(array $data, $callback = null)
    {
        var_dump(array_filter($data, $callback));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\FuncCall\DowngradeArrayFilterNullableCallbackRector\Fixture;

class MayBeNullFromParam
{
    public function run(array $data, $callback = null)
    {
        var_dump(array_filter($data, $callback === null ? fn($value, $key): bool => !empty($value) : $callback, $callback === null ? ARRAY_FILTER_USE_BOTH : 0));
    }
}

?>
