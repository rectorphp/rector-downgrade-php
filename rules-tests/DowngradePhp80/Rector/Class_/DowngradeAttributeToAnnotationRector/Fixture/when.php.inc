<?php

namespace Symfony\Component\DependencyInjection\Attribute;

#[\Attribute]
class When
{
    public function __construct(
        public string $env,
    ) {
    }
}
?>
-----
<?php

namespace Symfony\Component\DependencyInjection\Attribute;

class When
{
    public function __construct(
        public string $env,
    ) {
    }
}
?>
