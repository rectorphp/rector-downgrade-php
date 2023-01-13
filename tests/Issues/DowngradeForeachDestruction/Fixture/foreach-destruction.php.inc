<?php

foreach (array(array(1, 2)) as [$a, $b]) {
    echo "$a $b";
}

?>
-----
<?php

foreach (array(array(1, 2)) as $arrayItem) {
    list($a, $b) = $arrayItem;
    echo "$a $b";
}

?>
