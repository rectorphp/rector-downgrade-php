<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma3
{
	public function run(string $foo, string $bar, string $baz)
    {}

    public function execute()
    {
        $this->run(
            bar: 'bar',
            baz: 'baz',
            foo: 'foo',
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma3
{
	public function run(string $foo, string $bar)
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
