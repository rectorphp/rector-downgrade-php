<?php

namespace Rector\Tests\Set\Fixture;

final class NamedArgumentTrailingComma2
{
	public function run(string $foo, string $bar)
    {}

    public function execute()
    {
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

final class NamedArgumentTrailingComma2
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
