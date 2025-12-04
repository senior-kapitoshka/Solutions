module Codewars.Kata.Middle where

-- | Return the index of the middle element.
--   The first element has index 0.
gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) 
  |(b>c || c>b) && ((a<b && a>c) || (a>b && a<c))=0
  |(a > c || c > a) && ((b<c && b>a) || (b>c && b<a)) = 1
  |otherwise = 2

---------------
module Codewars.Kata.Middle where
import Data.List

-- | Return the index of the middle element.
--   The first element has index 0.
gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) = snd . (!! 1) . sort $ zip [a,b,c] [0..]  

-------------

module Codewars.Kata.Middle where

-- | Return the index of the middle element.
--   The first element has index 0.
gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) 
  | between a (b,c) = 0
  | between b (a,c) = 1
  | between c (a,b) = 2
  | otherwise       = error "Input not within kata specification"
  where between x (y,z) = (y < x && x < z) || (z < x && x < y)

 ------------
 module Codewars.Kata.Middle where
import Data.List (elemIndex, sort)
import Data.Maybe (fromJust)

gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) = fromJust (elemIndex m xs)
    where xs = [a,b,c]
          m  = sort [a,b,c] !! 1

-----------------
module Codewars.Kata.Middle where

between :: Ord a => a -> (a, a) -> Bool
between a (b, c) = (a > b && a < c) || (a < b && a > c)


gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) | between a (b, c) = 0
gimme (a, b, c) | between b (a, c) = 1
gimme (a, b, c) | between c (a, b) = 2

--------------
module Codewars.Kata.Middle where
import Data.Bits
-- | Return the index of the middle element.
--   The first element has index 0.

gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) 
 | (a > b) `xor` (a > c) = 0
 | (b > a) `xor` (b > c) = 1
 | otherwise = 2

 ------------
 module Codewars.Kata.Middle where

import Data.List (sortOn)

-- | Return the index of the middle element.
--   The first element has index 0.
gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) =
  let [_, (i, _), _] = sortOn snd [(0, a), (1, b), (2, c)]
   in i

 ------------
 module Codewars.Kata.Middle where

import Data.List (findIndex)
import Data.Maybe (fromJust)

-- | Return the index of the middle element.
--   The first element has index 0.
gimme :: Ord a => (a, a, a) -> Int
gimme (a, b, c) = fromJust $ findIndex (\x -> x /= minn && x /= maxx) lst
  where
    lst = [a,b,c]
    maxx = maximum lst
    minn = minimum lst  