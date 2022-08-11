<?php

function inFunctionNoNamespace()
{
    return new class {
            public function execute()
            {
            }
    };
}
-----
<?php

function inFunctionNoNamespace()
{
    return new Anonymous__%s();
}
class Anonymous__%s
{
    public function execute()
    {
    }
}
