module WordsToSentence where

wordsToSentence :: [[Char]] -> [Char]
wordsToSentence = unwords

--------------
module WordsToSentence where

import Data.List

wordsToSentence :: [[Char]] -> [Char]
wordsToSentence = intercalate " "