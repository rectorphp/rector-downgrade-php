<?php

namespace Rector\Tests\DowngradePhp80\Rector\StaticCall\DowngradePhpTokenRector\Fixture;

class SkipExtendsInternalPhpParserToken extends \PhpParser\Internal\TokenPolyfill
{
    public function run()
    {
        return $this->text;
    }

    public function run2()
    {
        $self = new self();
        return $self->text;
    }
}
