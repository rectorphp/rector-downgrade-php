<?php

function () {
    return new class {
            public function execute()
            {
            }
    };
};

?>
-----
<?php

function () {
    return new Anonymous__%s();
};
class Anonymous__%s
{
    public function execute()
    {
    }
}
