<?php

namespace Rector\Tests\Issues\DowngradeNamedTrailing\Fixture;

class Fixture
{
    public function __construct(
        protected string $type,
        array $data = [],
        protected ?string $id = null,
        protected ?int $version = null,
        protected ?string $key = null,
        protected ?string $internalId = null,
        protected ?string $externalId = null,
    ) {
        $this->setData($data);
    }
}

$contents = new Fixture(
    $content->getType(),
    id: $content->getId(),
    data: ['error' => $e->getMessage()]
);

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeNamedTrailing\Fixture;

class Fixture
{
    public function __construct(
        protected string $type,
        array $data = [],
        protected ?string $id = null,
        protected ?int $version = null,
        protected ?string $key = null,
        protected ?string $internalId = null,
        protected ?string $externalId = null,
    ) {
        $this->setData($data);
    }
}

$contents = new Fixture(
    $content->getType(),
    ['error' => $e->getMessage()],
    $content->getId()
);

?>
