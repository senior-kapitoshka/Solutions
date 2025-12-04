module LargestPairSum (largestPairSum) where

import Data.List (sort)

largestPairSum :: (Integral a) => [a] -> a
largestPairSum [x,y] = x+y
largestPairSum lst = add $ reverse $ sort lst 
  where
    add (x:y:zs) = x+y

------------------
module LargestPairSum (largestPairSum) where

import Data.List
import Data.Ord

largestPairSum :: (Integral a) => [a] -> a
largestPairSum = sum . take 2 . sortOn Down

----------------
module LargestPairSum (largestPairSum) where
import Data.List

largestPairSum :: (Integral a) => [a] -> a
largestPairSum = sum . take 2 . reverse . sort

------------
module LargestPairSum (largestPairSum) where

largestPairSum :: (Integral a) => [a] -> a
largestPairSum arr = worker (head arr) (arr !! 1) (drop 2 arr)
  where
    worker a b [] = a + b
    worker a b (x:xs) 
      | a < b && x > a = worker x b xs
      | x > b = worker a x xs
      | otherwise = worker a b xs

-------------
      