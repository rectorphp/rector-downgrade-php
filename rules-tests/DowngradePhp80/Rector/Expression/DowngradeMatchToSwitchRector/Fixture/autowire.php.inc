<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class Autowire
{
    public function __construct()
    {
        $this->value = match (true) {
            null !== $expression => class_exists(Expression::class) ? new Expression($expression) : throw new LogicException('Some error message.'),
            default => $value,
        };
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeMatchToSwitchRector\Fixture;

class Autowire
{
    public function __construct()
    {
        switch (\true) {
            case null !== $expression:
                if (!\class_exists(Expression::class)) {
                    throw new LogicException('Some error message.');
                }
                $this->value = new Expression($expression);
                break;
            default:
                $this->value = $value;
                break;
        }
    }
}

?>
