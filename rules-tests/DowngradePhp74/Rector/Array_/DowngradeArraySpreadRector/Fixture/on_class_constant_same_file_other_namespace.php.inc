<?php

namespace OtherNamespace {
    class SomeTokens
    {
        public const TOKEN = 'token';
    }

    class ClassWithArrayConstant
    {
        public const ITEMS = ['a', SomeTokens::TOKEN];
    }
}

namespace App {
    use OtherNamespace\ClassWithArrayConstant;

    final class OnClassConstantOtherNamespace extends ClassWithArrayConstant
    {
        private const FROM_OTHER = ['x', ...ClassWithArrayConstant::ITEMS];
    }
}

?>
-----
<?php

namespace OtherNamespace {
    class SomeTokens
    {
        public const TOKEN = 'token';
    }

    class ClassWithArrayConstant
    {
        public const ITEMS = ['a', SomeTokens::TOKEN];
    }
}

namespace App {
    use OtherNamespace\ClassWithArrayConstant;

    final class OnClassConstantOtherNamespace extends ClassWithArrayConstant
    {
        private const FROM_OTHER = ['x', 'a', \OtherNamespace\SomeTokens::TOKEN];
    }
}

?>
