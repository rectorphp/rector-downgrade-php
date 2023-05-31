<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class DefinedVar
{
    public function run()
    {
        if (rand(0, 1)) {
        } elseif (rand(0, 1)) {
        } else {
            $all = $this->definition->getArguments();
            $symfonyCommandName = null;
            if (($inputArgument = $all[$key = array_key_first($all)] ?? null) && 'command' === $inputArgument->getName()) {
                $symfonyCommandName = $this->arguments['command'] ?? null;
                unset($all[$key]);
            }
        }
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\FuncCall\DowngradeArrayKeyFirstLastRector\Fixture;

class DefinedVar
{
    public function run()
    {
        if (rand(0, 1)) {
        } elseif (rand(0, 1)) {
        } else {
            $all = $this->definition->getArguments();
            $symfonyCommandName = null;
            reset($all);
            if (($inputArgument = $all[$key = key($all)] ?? null) && 'command' === $inputArgument->getName()) {
                $symfonyCommandName = $this->arguments['command'] ?? null;
                unset($all[$key]);
            }
        }
    }
}

?>