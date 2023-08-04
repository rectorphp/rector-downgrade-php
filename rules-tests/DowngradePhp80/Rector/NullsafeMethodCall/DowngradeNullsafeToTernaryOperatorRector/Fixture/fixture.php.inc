<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

class Fixture
{
    public function run($booking)
    {
        // with argument
        $dateAsString = $booking->getStartDate($args1)?->asDateTimeString($arg2);

        // without argument, one is method call, next property fetch
        $dateAsString = $booking->getStartDate()?->asDateTimeString;

        // without argument, one is property call, next method fetch
        $dateAsString = $booking->getStartDate?->asDateTimeString();

        // all are property fetch
        $dateAsString = $booking->getStartDate?->asDateTimeString;

        $getStartDate = true;
        $bookingGetStartDate = true;

        // previously named vars aren't reused
        $dateAsString = $booking->getStartDate?->asDateTimeString;
    }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\NullsafeMethodCall\DowngradeNullsafeToTernaryOperatorRector\Fixture;

class Fixture
{
    public function run($booking)
    {
        // with argument
        $dateAsString = ($nullsafeVariable1 = $booking->getStartDate($args1)) ? $nullsafeVariable1->asDateTimeString($arg2) : null;

        // without argument, one is method call, next property fetch
        $dateAsString = ($nullsafeVariable2 = $booking->getStartDate()) ? $nullsafeVariable2->asDateTimeString : null;

        // without argument, one is property call, next method fetch
        $dateAsString = ($nullsafeVariable3 = $booking->getStartDate) ? $nullsafeVariable3->asDateTimeString() : null;

        // all are property fetch
        $dateAsString = ($nullsafeVariable4 = $booking->getStartDate) ? $nullsafeVariable4->asDateTimeString : null;

        $getStartDate = true;
        $bookingGetStartDate = true;

        // previously named vars aren't reused
        $dateAsString = ($nullsafeVariable5 = $booking->getStartDate) ? $nullsafeVariable5->asDateTimeString : null;
    }
}

?>
