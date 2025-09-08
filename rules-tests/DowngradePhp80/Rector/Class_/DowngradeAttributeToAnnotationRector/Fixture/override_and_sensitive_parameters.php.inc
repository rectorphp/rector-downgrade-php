<?php

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

final class OverrideAndSensitiveParameter extends Foo
{
    #[\Override]
    public function run(#[\SensitiveParameter]
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