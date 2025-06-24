module FruitNinjaI where

import Fruits 
-- defines fruits :: [String]

cutFruits :: [String] -> [String]
cutFruits arr = concatMap slice arr
  where 
    slice fruit
      |elem fruit fruits = let (a,b) = splitAt (div (length fruit + 1) 2) fruit
                            in [a,b]
      |otherwise = [fruit]        

      --


      module FruitNinjaI where

import Fruits 
-- defines fruits :: [String]
import Data.List

cutFruits :: [String] -> [String]
cutFruits = concatMap cut
  where
    cut item
      | item `elem` fruits = [take lg item, drop lg item]
      | otherwise = [item]
      where lg = (length item + 1) `div` 2