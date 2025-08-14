module TwoHighest (twoHighest) where

import Data.List (nub,sort)

twoHighest :: (Ord a) => [a] -> [a]
twoHighest a = take 2 (reverse (nub (sort a))) 