<?php

namespace Rector\Tests\DowngradePhp80\Rector\Param\DowngradeInlinedAttributeRector\Fixture;

function skip_already_next_line(
    #[\JetBrains\PhpStorm\Language('RegExp')]
    string $pattern
){}
