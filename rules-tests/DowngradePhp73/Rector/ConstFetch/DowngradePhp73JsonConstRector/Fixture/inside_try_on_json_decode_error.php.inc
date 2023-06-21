<?php

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

// Class
class DowngradePhp73JsonConstRectorFixture
{
    public function method_json_decode(string $json): string | bool
    {
        try {
            $payload = json_decode($json, null, 512, JSON_THROW_ON_ERROR);
            return $payload;
        } catch (\Exception $e) {
            return false;
        }
    }

    public function method_json_decode_multi_flags(string $json): string | bool
    {
        try {
            $payload = json_decode($json, null, 512, JSON_OBJECT_AS_ARRAY | JSON_THROW_ON_ERROR);
            return $payload;
        } catch (\Exception $e) {
            return false;
        }
    }
}

// Function
function func_json_decode(string $json): string | bool
{
    try {
        $payload = json_decode($json, null, 512, JSON_THROW_ON_ERROR);
        return $payload;
    } catch (\Exception $e) {
        return false;
    }
}

// Standalone
$decode = json_decode($json, null, 512, JSON_THROW_ON_ERROR);

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

// Class
class DowngradePhp73JsonConstRectorFixture
{
    public function method_json_decode(string $json): string | bool
    {
        try {
            $payload = json_decode($json, null, 512, 0);
            return $payload;
        } catch (\Exception $e) {
            return false;
        }
    }

    public function method_json_decode_multi_flags(string $json): string | bool
    {
        try {
            $payload = json_decode($json, null, 512, JSON_OBJECT_AS_ARRAY);
            return $payload;
        } catch (\Exception $e) {
            return false;
        }
    }
}

// Function
function func_json_decode(string $json): string | bool
{
    try {
        $payload = json_decode($json, null, 512, 0);
        return $payload;
    } catch (\Exception $e) {
        return false;
    }
}

// Standalone
$decode = json_decode($json, null, 512, 0);
if (json_last_error() !== JSON_ERROR_NONE) {
    throw new \Exception(json_last_error_msg());
}

?>
