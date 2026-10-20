<?php

namespace Rector\Tests\DowngradePhp82\Rector\FuncCall\DowngradeIteratorCountToArrayRector\Fixture;

final class SkipIsArrayGuarded
{
    private $data;

    public function run($data)
    {
        return is_array($data) ? $data : iterator_to_array($data);
    }

    public function run2($data)
    {
        return ! is_array($data) ? iterator_count($data) : count($data);
    }

    public function run3()
    {
        return array_merge(is_array($this->data) ? $this->data : iterator_to_array($this->data), []);
    }

    public function run4(SomeUnknownClass $object)
    {
        return array_merge(is_array($object->getItems()) ? $object->getItems() : iterator_to_array($object->getItems()), []);
    }

    public function run5()
    {
        return is_array($this->getItems()) ? $this->getItems() : iterator_to_array($this->getItems());
    }

    private function getItems()
    {
        return [];
    }
}
