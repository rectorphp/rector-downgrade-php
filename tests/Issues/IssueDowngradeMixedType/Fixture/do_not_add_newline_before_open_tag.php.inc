<?php declare(strict_types=1);

namespace Rector\Tests\Issues\IssueDowngradeMixedType\Fixture;

class SkipSameLineDeclareStrictType extends \stdClass implements \ArrayAccess, \Countable, \IteratorAggregate
{
    public function offsetGet($key): mixed
    {
    }
}

?>
-----
<?php declare(strict_types=1);

namespace Rector\Tests\Issues\IssueDowngradeMixedType\Fixture;

use stdClass;
use ArrayAccess;
use Countable;
use IteratorAggregate;
use ReturnTypeWillChange;

class SkipSameLineDeclareStrictType extends stdClass implements ArrayAccess, Countable, IteratorAggregate
{
    /**
     * @return mixed
     */
    #[ReturnTypeWillChange]
    public function offsetGet($key)
    {
    }
}

?>
