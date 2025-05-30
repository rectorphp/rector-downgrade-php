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
        $this->run(
            'foo',
            'bar'
        );
    }
}

?>
