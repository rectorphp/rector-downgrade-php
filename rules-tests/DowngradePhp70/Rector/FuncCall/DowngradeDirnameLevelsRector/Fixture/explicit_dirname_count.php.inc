<?php

namespace Rector\Tests\DowngradePhp70\Rector\FuncCall\DowngradeDirnameLevelsRector\Fixture;

final class ExplicitDirnameCount
{
    public function dirnameWithFixedLevels($path)
    {
        $result = dirname($path, 1);
        $secondResult = dirname($path, 2);
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp70\Rector\FuncCall\DowngradeDirnameLevelsRector\Fixture;

final class ExplicitDirnameCount
{
    public function dirnameWithFixedLevels($path)
    {
        $result = dirname($path);
        $secondResult = dirname(dirname($path));
    }
}

?>
