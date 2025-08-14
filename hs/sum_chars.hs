module Kata (wordsToMarks) where

import Data.Char (ord)

wordsToMarks :: String -> Int
wordsToMarks str = sum ( map (\x-> (ord x)-96) str)

------
module Kata (wordsToMarks) where

import Data.Char

wordsToMarks :: String -> Int
wordsToMarks = sum . map (\x -> ord x - 96)

--------
module Kata (wordsToMarks) where
import Data.Char (ord)


wordsToMarks :: String -> Int
wordsToMarks s = sum [ ord n - 96 | n <- s ]

-------
module Kata (wordsToMarks) where
import Data.Char

wordsToMarks :: String -> Int
wordsToMarks [] = 0
wordsToMarks (x:xs) = ord(x) - 96 + wordsToMarks xs