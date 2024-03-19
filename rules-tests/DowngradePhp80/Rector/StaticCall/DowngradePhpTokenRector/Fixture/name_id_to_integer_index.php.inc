<?php

namespace Rector\Tests\DowngradePhp80\Rector\StaticCall\DowngradePhpTokenRector\Fixture;

$code = '<?php echo 1;';
$tokens = \PhpToken::tokenize($code, TOKEN_PARSE);

while ($token = current($tokens)) {
   next($tokens);
   switch ($token->id) {

   }
}

?>
-----
<?php

namespace Rector\Tests\DowngradePhp80\Rector\StaticCall\DowngradePhpTokenRector\Fixture;

$code = '<?php echo 1;';
$tokens = token_get_all($code, TOKEN_PARSE);

while ($token = current($tokens)) {
   next($tokens);
   switch (is_array($token) ? $token[0] : $token) {

   }
}

?>
