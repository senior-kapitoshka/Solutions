module Unsorted where

import qualified Data.Set as Set

findDup :: [Int] -> Int
findDup lst = check Set.empty lst
  where
    check set (x:xs)
      | Set.member x set = x
      | otherwise = check (Set.insert x set) xs  

-----------------
module Unsorted where

findDup :: [Int] -> Int
findDup xs = (sum xs) - sum [1..maximum xs]
----------
module Unsorted where

findDup :: [Int] -> Int
findDup xs = sum xs - n*(n-1)`div`2
  where
    n = length xs

    ------------
    