module SortingIntegersIntoANestedList (groupInts) where

groupInts :: [Int] -> Int -> [[Int]]
groupInts [] _ = []
groupInts lst k = walk lst k [] []
  where
    walk [] k tmp res = res ++ [tmp]
    walk (x:xs) k tmp res
      | ((x < k) && (length tmp == 0)) || ((x >= k) && (length tmp == 0)) = walk xs k [x] res
      | ((x < k) && (last tmp < k)) || ((x >= k) && (last tmp >= k))= walk xs k (tmp ++ [x]) res
      | otherwise = walk xs k [x] (res ++ [tmp])

-----------------
module SortingIntegersIntoANestedList (groupInts) where
import Data.List

import Data.Function (on)

groupInts :: [Int] -> Int -> [[Int]]
groupInts xs n = groupBy ((==) `on` (<n)) xs

--------------
module SortingIntegersIntoANestedList (groupInts) where

import Data.List (groupBy)

groupInts :: [Int] -> Int -> [[Int]]
groupInts xs k = groupBy (\x y -> (x < k) == (y < k)) xs

--------------
module SortingIntegersIntoANestedList (groupInts) where

import Data.List

groupInts :: [Int] -> Int -> [[Int]]
groupInts xs k = groupBy (\x y -> (x < k && y < k) || (x >= k && y >= k)) xs