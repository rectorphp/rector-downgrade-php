<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class NoIssetOnExpr
{
    public function run($backedEnumClassName, $backedEnumValue)
    {
        return $backedEnumClassName::tryFrom($backedEnumValue) ?? throw new \Symfony\Component\DependencyInjection\Exception\RuntimeException(sprintf('Enum value "%s" is not backed by "%s".', $backedEnumValue, $backedEnumClassName));
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Expression\DowngradeThrowExprRector\Fixture;

final class NoIssetOnExpr
{
    public function run($backedEnumClassName, $backedEnumValue)
    {
        if ($backedEnumClassName::tryFrom($backedEnumValue) !== null) {
            throw new \Symfony\Component\DependencyInjection\Exception\RuntimeException(sprintf('Enum value "%s" is not backed by "%s".', $backedEnumValue, $backedEnumClassName));
        }
        return $backedEnumClassName::tryFrom($backedEnumValue);
    }
}

?>
