<?php

return new class {
    public function execute()
    {
    }
};
-----
<?php

return new Anonymous__%s();
class Anonymous__%s
{
    public function execute()
    {
    }
}
