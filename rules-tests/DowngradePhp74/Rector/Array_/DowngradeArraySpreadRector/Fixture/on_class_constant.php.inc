<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

abstract class OnClassConstant
{
    private const TYPE_END_TOKENS = [')', [T_CALLABLE], [T_NS_SEPARATOR], [T_STATIC], [T_STRING], [CT::T_ARRAY_TYPEHINT]];

    private const TYPE_TOKENS = [
        '|', '&', '(',
        ...self::TYPE_END_TOKENS,
        [CT::T_TYPE_ALTERNATION], [CT::T_TYPE_INTERSECTION],
        [T_WHITESPACE], [T_COMMENT], [T_DOC_COMMENT],
    ];
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp74\Rector\Array_\DowngradeArraySpreadRector\Fixture;

abstract class OnClassConstant
{
    private const TYPE_END_TOKENS = [')', [T_CALLABLE], [T_NS_SEPARATOR], [T_STATIC], [T_STRING], [CT::T_ARRAY_TYPEHINT]];

    private const TYPE_TOKENS = ['|', '&', '(', ')', [T_CALLABLE], [T_NS_SEPARATOR], [T_STATIC], [T_STRING], [CT::T_ARRAY_TYPEHINT], [CT::T_TYPE_ALTERNATION], [CT::T_TYPE_INTERSECTION], [T_WHITESPACE], [T_COMMENT], [T_DOC_COMMENT]];
}

?>
