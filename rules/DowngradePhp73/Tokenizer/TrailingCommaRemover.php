<?php

declare(strict_types=1);

namespace Rector\DowngradePhp73\Tokenizer;

use PhpParser\Node;
use Rector\ValueObject\Application\File;

final class TrailingCommaRemover
{
    public function remove(File $file, Node $node, ?Node $previousNode = null): void
    {
        $tokens = $file->getOldTokens();
        $iteration = 1;

        while (isset($tokens[$node->getEndTokenPos() + $iteration])) {
            if (trim($tokens[$node->getEndTokenPos() + $iteration]->text) === '') {
                ++$iteration;
                continue;
            }

            if (trim($tokens[$node->getEndTokenPos() + $iteration]->text) !== ',') {
                break;
            }

            // position just swapped
            if ($previousNode instanceof Node && $previousNode->getEndTokenPos() > $node->getEndTokenPos()) {
                $this->remove($file, $previousNode);
                break;
            }

            $tokens[$node->getEndTokenPos() + $iteration]->text = '';
            break;
        }
    }
}
