module Codewars.Kata.Sort where
import Data.List (sort, intercalate)

twoSort :: [String] -> String
twoSort xs = intercalate "***"  (map (:[])(head (sort xs)))

{-
sort xs — сортирует список строк.

head — берёт первую строку.

map (:[]) — превращает строку в список строк по одному символу: "abc" → ["a", "b", "c"]

intercalate "***" — вставляет "***" между элементами: ["a","b","c"] → "a***b***c"
-}

--

module Codewars.Kata.Sort where

import Data.List (intercalate)

twoSort :: [String] -> String
twoSort = intercalate "***" . map pure . minimum

--

module Codewars.Kata.Sort where
import Data.List(intercalate, sort)
twoSort :: [String] -> String
twoSort = intercalate "***" . map (:"") . head . sort

--

