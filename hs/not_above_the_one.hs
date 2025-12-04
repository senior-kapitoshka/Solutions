module NotAboveTheOne (binaryCleaner) where

import Data.List (partition) 

binaryCleaner :: [Int] -> ( [Int], [Int] )
binaryCleaner l = part (zip [0..] l) ([],[]) 
  where
    part [] (bin,idx) = (reverse bin,reverse idx)
    part ((x,y):xs) (bin,idx)
      | y == 0 || y == 1 = part xs (y:bin,idx)
      | otherwise = part xs (bin,x:idx)

------------------
module NotAboveTheOne (binaryCleaner) where

import Data.List (findIndices)

binaryCleaner :: [Int] -> ( [Int], [Int] )
binaryCleaner xs = (filter (<= 1) xs, findIndices (> 1) xs)

--------------
module NotAboveTheOne (binaryCleaner) where
import Data.Bifunctor
import Data.List

binaryCleaner :: [Int] -> ( [Int], [Int] )
binaryCleaner =  bimap (map snd) (map fst) . partition ((<2) . snd) . zip [0..]

------------
module NotAboveTheOne (binaryCleaner) where

import Data.List (partition)

binaryCleaner :: [Int] -> ( [Int], [Int] )
binaryCleaner xs = (map snd p2, map fst p1)
  where (p1, p2) = partition (\ (i, x) -> x > 1) $ zip [0..] xs

  -----------
  module NotAboveTheOne (binaryCleaner) where
import Data.List (findIndices)
import Control.Arrow ((&&&))


binaryCleaner :: [Int] -> ( [Int], [Int] )
binaryCleaner = filter (<2) &&& findIndices (>1)