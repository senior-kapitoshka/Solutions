module Sorted where

import Data.List (sortBy)
import Data.Ord (comparing)

sortList :: Ord b => (a -> b) -> [a] -> [a]
sortList f = sortBy $ comparing f

---------------
module Sorted where

import Data.Ord
import Data.List

sortList :: Ord b => (a -> b) -> [a] -> [a]
sortList = sortBy . comparing

----------
module Sorted where
import Data.List

sortList :: Ord b => (a -> b) -> [a] -> [a]
sortList = sortOn

----------
