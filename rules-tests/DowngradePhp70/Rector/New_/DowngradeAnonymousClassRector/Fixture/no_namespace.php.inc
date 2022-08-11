<?php

class NoNamespace
{
    public function run()
    {
        return new class {
            public function execute()
            {
            }
        };
    }
}
-----
<?php

class NoNamespace
{
    public function run()
    {
        return new Anonymous__%s();
    }
}
class Anonymous__%s
{
    public function execute()
    {
    }
}
