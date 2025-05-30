<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma
{
	public function run(string $foo, string $bar)
    {}

    public function execute()
    {
        $this->run(
            foo: 'foo',
            bar: 'bar',
        );

        $this->run(
            bar: 'bar',
            foo: 'foo',
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma
{
	public function run(string $foo, string $bar)
    {}

    public function execute()
    {
        $this->run('foo', 'bar');

        $this->run('foo', 'bar');
    }
}

?>
