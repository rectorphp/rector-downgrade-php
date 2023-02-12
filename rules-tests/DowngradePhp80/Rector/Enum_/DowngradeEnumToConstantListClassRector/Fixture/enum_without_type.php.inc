<?php

enum NotBackedEnum
{
    case ONE;
    case TWO;
    case THREE;

    public static function one(): self
    {
        return self::ONE;
    }

    public static function two(): static
    {
        return self::TWO;
    }

    public static function three(): NotBackedEnum
    {
        return self::THREE;
    }

    public static function oneValue(): string
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

class NotBackedEnum
{
    public const ONE = 'one';
    public const TWO = 'two';
    public const THREE = 'three';
    public static function one(): string
    {
        return self::ONE;
    }
    public static function two(): string
    {
        return self::TWO;
    }
    public static function three(): string
    {
        return self::THREE;
    }
    public static function oneValue(): string
    {
        return self::ONE;
    }
    public static function oneName(): string
    {
        return 'ONE';
    }
    /**
     * @param \NotBackedEnum::* $left
     * @param \NotBackedEnum::* $right
     */
    public static function equalsTo(string $left, string $right): bool
    {
        return $left === $right;
    }
}


?>
