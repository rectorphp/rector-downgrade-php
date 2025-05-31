<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma4
{
	public function run(string $foo, string $bar, string $baz)
    {}

    public function execute()
    {
        $this->run(
            baz: 'baz',
            foo: 'foo',
            bar: 'bar',
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma4
{
	public function run(string $foo, string $bar, string $baz)
    {}

    public function execute()
    {
        $this->run(
            'foo',
            'bar',
            'baz'
        );
    }
}

?>
