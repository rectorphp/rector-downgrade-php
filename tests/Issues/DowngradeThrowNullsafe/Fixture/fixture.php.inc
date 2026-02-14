<?php

namespace Rector\Tests\Issues\DowngradeThrowNullsafe\Fixture;

class Fixture
{
    public function run($s)
    {
        $s = \Transliterator::create('Any-Latin; Latin-ASCII')?->transliterate($s)
	    	?? throw new Nette\InvalidStateException('Transliterator::transliterate() failed.');
    }
}

?>
-----
<?php

namespace Rector\Tests\Issues\DowngradeThrowNullsafe\Fixture;

class Fixture
{
    public function run($s)
    {
        if ((($nullsafeVariable1 = \Transliterator::create('Any-Latin; Latin-ASCII')) ? $nullsafeVariable1->transliterate($s) : null) === null) {
            throw new Nette\InvalidStateException('Transliterator::transliterate() failed.');
        }
        $s = ($nullsafeVariable2 = \Transliterator::create('Any-Latin; Latin-ASCII')) ? $nullsafeVariable2->transliterate($s) : null;
    }
}

?>
