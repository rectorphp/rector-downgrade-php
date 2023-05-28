<?php

namespace Rector\Tests\DowngradePhp70\Rector\FuncCall\DowngradeDirnameLevelsRector\Fixture;

final class SkipSimpleDirname
{
    public function simpleDirname($path)
    {
        return dirname($path);
    }
}
