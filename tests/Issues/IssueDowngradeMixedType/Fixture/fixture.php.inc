<?php

declare(strict_types=1);

namespace Rector\Tests\Issues\IssueDowngradeMixedType\Fixture;

use Rector\Tests\Issues\IssueDowngradeMixedType\Source\SomeClass;

class AnotherClass
{
    private SomeClass $foo;

    public function bar(SomeClass $baz)
    {
    }
}

?>
-----
<?php

declare(strict_types=1);

namespace Rector\Tests\Issues\IssueDowngradeMixedType\Fixture;

use Rector\Tests\Issues\IssueDowngradeMixedType\Source\SomeClass;

class AnotherClass
{
    /**
     * @var SomeClass
     */
    private $foo;

    public function bar(SomeClass $baz)
    {
    }
}

?>
