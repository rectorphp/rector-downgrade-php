<?php

namespace App {
    enum Enum: string
    {
        case ONE = 'one';
        case TWO = 'two';
        case THREE = 'three';

        public function mixed(null|self|Enum|string $value)
        {

        }
    }
}
namespace Tests{

    use App\Enum;

    class Analyser{
        public function analyse(?\App\Enum $enum): Enum|bool
        {
            if ($enum === Enum::ONE) {
                return Enum::TWO;
            }
            if ($enum === Enum::TWO) {
                return false;
            }
            return $enum;
        }
    }
}


?>
-----
<?php

namespace App {
    class Enum
    {
        public const ONE = 'one';
        public const TWO = 'two';
        public const THREE = 'three';
        /**
         * @param (null | \App\Enum::* | string) $value
         */
        public function mixed(null|string $value)
        {

        }
    }
}
namespace Tests{

    use App\Enum;

    class Analyser{
        /**
         * @param ?\App\Enum::* $enum
         */
        public function analyse(?string $enum): string|bool
        {
            if ($enum === Enum::ONE) {
                return Enum::TWO;
            }
            if ($enum === Enum::TWO) {
                return false;
            }
            return $enum;
        }
    }
}


?>
