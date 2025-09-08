<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

final class OverrideAndSensitiveParameter extends Foo
{
    #[\Override]
    public function run(#[\SensitiveParameter] bool $param) {
        if ($this->isTrue($param)) {
            return 5;
        }

        return '10';
    }

    private function isTrue($value) {
        return $value === true;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\Class_\DowngradeAttributeToAnnotationRector\Fixture;

final class OverrideAndSensitiveParameter extends Foo
{
    #[\Override]
    public function run(
#[\SensitiveParameter]
 bool $param) {
        if ($this->isTrue($param)) {
            return 5;
        }

        return '10';
    }

    private function isTrue($value) {
        return $value === true;
    }
}

?>