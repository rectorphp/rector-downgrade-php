<?php

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

// Class
class DowngradePhp73JsonConstRectorFixture
{
    public function method_json_encode(string $json): string | bool
    {
        try {
            json_encode($json, JSON_THROW_ON_ERROR);
        } catch (\Exception $e) {
            return false;
        }
    }

    public function method_json_encode_multi_flags(string $json): string | bool
    {
        try {
            json_encode($json, JSON_THROW_ON_ERROR | JSON_PRETTY_PRINT);
        } catch (\Exception $e) {
            return false;
        }
    }
}

// Function
function func_json_encode(string $json): string | bool
{
    try {
        json_encode($json, JSON_THROW_ON_ERROR);
    } catch (\Exception $e) {
        return false;
    }
}

// Standalone
json_encode($json, JSON_THROW_ON_ERROR);

?>
-----
<?php

namespace Rector\Tests\DowngradePhp73\Rector\ConstFetch\DowngradePhp73JsonConstRector\Fixture;

// Class
class DowngradePhp73JsonConstRectorFixture
{
    public function method_json_encode(string $json): string | bool
    {
        try {
            json_encode($json, 0);
        } catch (\Exception $e) {
            return false;
        }
    }

    public function method_json_encode_multi_flags(string $json): string | bool
    {
        try {
            json_encode($json, JSON_PRETTY_PRINT);
        } catch (\Exception $e) {
            return false;
        }
    }
}

// Function
function func_json_encode(string $json): string | bool
{
    try {
        json_encode($json, 0);
    } catch (\Exception $e) {
        return false;
    }
}

// Standalone
json_encode($json, 0);
if (json_last_error() !== JSON_ERROR_NONE) {
    throw new \Exception(json_last_error_msg());
}

?>
