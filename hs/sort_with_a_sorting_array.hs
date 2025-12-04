module Codewars.ArraySort (sortArray) where
import Data.List (sortOn)

sortArray :: [a] -> [Int] -> [a]
sortArray xs ys = fst(unzip (sortOn snd (zip xs ys)))

-------------
module Codewars.ArraySort where

import GHC.Exts

sortArray :: [a] -> [Int] -> [a]
sortArray = ((map fst . sortWith snd) .) . zip

----------
module Codewars.ArraySort where

import Data.List

sortArray :: [a] -> [Int] -> [a]
sortArray xs ys = map snd . sortOn fst $ zip ys xs

-----------
module Codewars.ArraySort (sortArray) where
import Data.List (sortBy)
import Data.Ord (comparing)

sortArray :: [a] -> [Int] -> [a]
sortArray xs = map fst . sortBy (comparing snd) . zip xs

-----------
module Codewars.ArraySort (sortArray) where
import Data.List
import Data.Ord

sortArray :: [a] -> [Int] -> [a]
sortArray xs ys = map fst sortedTups
  where tups = zip xs ys
        sortedTups = sortBy (comparing snd) tups