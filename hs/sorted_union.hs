module Codewars.Kata.SortedUnion where

import Data.List (nub)

uniteUnique :: Ord a => [[a]] -> [a]
uniteUnique xs = nub $ concat xs

-----------
module Codewars.Kata.SortedUnion where
import Data.List (union)

uniteUnique :: Ord a => [[a]] -> [a]
uniteUnique = foldl union []

----------
module Codewars.Kata.SortedUnion where

import Data.List

uniteUnique :: Ord a => [[a]] -> [a]
uniteUnique = nub . concat

----------
module Codewars.Kata.SortedUnion where

import Data.List

uniteUnique :: Ord a => [[a]] -> [a]
uniteUnique = nub . concat . map nub