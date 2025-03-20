<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

class NoParamsDuplicatedInUse
{
    public function single()
    {
        $callable = fn($param) => $param;
    }

    public function singleArrayAssignment()
    {
        $callable = fn($param) => $arr[] = $param;
    }

    public function multiple()
    {
        $callable = fn($param, $param2) => $param + $param2;
    }

    public function multipleArrayAssignment()
    {
        $callable = fn($param, $param2) => $arr[] = $param + $param2;
    }

    public function mixed()
    {
        $callable = fn($param) => $param + $param2;
    }

    public function mixedArrayAssignment()
    {
        $callable = fn($param) => $arr[] = $param + $param2;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\ArrowFunction\ArrowFunctionToAnonymousFunctionRector\Fixture;

class NoParamsDuplicatedInUse
{
    public function single()
    {
        $callable = function ($param) {
            return $param;
        };
    }

    public function singleArrayAssignment()
    {
        $callable = function ($param) use ($arr) {
            return $arr[] = $param;
        };
    }

    public function multiple()
    {
        $callable = function ($param, $param2) {
            return $param + $param2;
        };
    }

    public function multipleArrayAssignment()
    {
        $callable = function ($param, $param2) use ($arr) {
            return $arr[] = $param + $param2;
        };
    }

    public function mixed()
    {
        $callable = function ($param) use ($param2) {
            return $param + $param2;
        };
    }

    public function mixedArrayAssignment()
    {
        $callable = function ($param) use ($arr, $param2) {
            return $arr[] = $param + $param2;
        };
    }
}

?>
