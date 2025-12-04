module Dictionaries where
import Data.List (sortOn)
import Data.Ord (Down(..))

sortDict :: Ord v => [(k,v)] -> [(k,v)]
sortDict [] = []
sortDict xs@((_,y):_) 
  | all ((==y) . snd) (xs) = xs
  | otherwise = sortOn (Down . snd) xs 

  ----------------

  module Dictionaries where
import Data.List (sortBy)
import Data.Ord  (comparing)

sortDict :: Ord v => [(k,v)] -> [(k,v)]
sortDict = sortBy (flip $ comparing snd)

------------
module Dictionaries where
import Data.List
import Data.Ord

sortDict :: Ord v => [(k,v)] -> [(k,v)]
sortDict = sortBy (comparing (Down . snd))

-----------
module Dictionaries where

import Data.List
import Data.Ord

sortDict :: Ord v => [(k,v)] -> [(k,v)]
sortDict = sortOn (Down . snd)

----------
