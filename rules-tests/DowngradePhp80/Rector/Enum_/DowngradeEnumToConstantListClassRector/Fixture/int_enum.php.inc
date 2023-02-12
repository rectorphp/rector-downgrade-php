<?php

enum IntEnum: int
{
    case ONE = 1;
    case TWO = 0;
    case THREE = -1;

    public static function one(): self
    {
        return self::ONE;
    }

    public static function two(): static
    {
        return self::TWO;
    }

    public static function three(): IntEnum
    {
        return self::THREE;
    }

    public static function oneValue(): int
    {
        return self::ONE->value;
    }

    public static function oneName(): string
    {
        return self::ONE->name;
    }

    public static function equalsTo(self $left, self $right): bool
    {
        return $left === $right;
    }
}


?>
-----
<?php

class IntEnum
{
    public const ONE = 1;
    public const TWO = 0;
    public const THREE = -1;
    public static function one(): int
    {
        return self::ONE;
    }
    public static function two(): int
    {
        return self::TWO;
    }
    public static function three(): int
    {
        return self::THREE;
    }
    public static function oneValue(): int
    {
        return self::ONE;
    }
    public static function oneName(): string
    {
        return 'ONE';
    }
    /**
     * @param \IntEnum::* $left
     * @param \IntEnum::* $right
     */
    public static function equalsTo(int $left, int $right): bool
    {
        return $left === $right;
    }
}


?>
