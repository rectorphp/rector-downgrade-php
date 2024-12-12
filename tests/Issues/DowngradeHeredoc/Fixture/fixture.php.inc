<?php

namespace Rector\Tests\Issues\DowngradeNullJson\DowngradeHeredoc;

class Fixture
{
    public function getDefinition(): FixerDefinitionInterface
    {
        return new FixerDefinition(
            'Sorts attributes using the configured sort algorithm.',
            [
                new VersionSpecificCodeSample(
                    <<<'EOL'
                        <?php

                        #[Foo]
                        #[Bar(3)]
                        #[Qux(new Bar(5))]
                        #[Corge(a: 'test')]
                        class Sample1 {}

                        #[
                            Foo,
                            Bar(3),
                            Qux(new Bar(5)),
                            Corge(a: 'test'),
                        ]
                        class Sample2 {}

                        EOL,
                    new VersionSpecification(8_00_00),
                ),
                new VersionSpecificCodeSample(
                    <<<'EOL'
                        <?php

                        use A\B\Foo;
                        use A\B\Bar as BarAlias;
                        use A\B as AB;

                        #[Foo]
                        #[BarAlias(3)]
                        #[AB\Qux(new Bar(5))]
                        #[\A\B\Corge(a: 'test')]
                        class Sample1 {}

                        EOL,
                    new VersionSpecification(8_00_00),
                    ['sort_algorithm' => self::ORDER_CUSTOM, 'order' => ['A\B\Qux', 'A\B\Bar', 'A\B\Corge']],
                ),
            ],
        );
    }
}

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeNullJson\DowngradeHeredoc;

class Fixture
{
    public function getDefinition(): FixerDefinitionInterface
    {
        return new FixerDefinition(
            'Sorts attributes using the configured sort algorithm.',
            [
                new VersionSpecificCodeSample(
                    <<<'EOL'
<?php

#[Foo]
#[Bar(3)]
#[Qux(new Bar(5))]
#[Corge(a: 'test')]
class Sample1 {}

#[
Foo,
Bar(3),
Qux(new Bar(5)),
Corge(a: 'test'),
]
class Sample2 {}

EOL
,
                    new VersionSpecification(80000)
                ),
                new VersionSpecificCodeSample(
                    <<<'EOL'
<?php

use A\B\Foo;
use A\B\Bar as BarAlias;
use A\B as AB;

#[Foo]
#[BarAlias(3)]
#[AB\Qux(new Bar(5))]
#[\A\B\Corge(a: 'test')]
class Sample1 {}

EOL
,
                    new VersionSpecification(80000),
                    ['sort_algorithm' => self::ORDER_CUSTOM, 'order' => ['A\B\Qux', 'A\B\Bar', 'A\B\Corge']]
                ),
            ]
        );
    }
}

?>
