module FrequencyFrenzy where

import Data.List (sort,group)

frequency :: Ord a => [a] -> [(a, Int)]
frequency xs = let grouping = group (sort xs) in
                map (\p->(head p,length p)) grouping 

-----------------
module FrequencyFrenzy where

import Data.List

frequency :: Ord a => [a] -> [(a, Int)]
frequency = map (\t -> (head t, length t)) . group . sort

--------------
module FrequencyFrenzy where

import Control.Arrow
import Data.List

frequency :: Ord a => [a] -> [(a, Int)]
frequency
   =  sort
  >>> group
  >>> map (head &&& length)

------------
  