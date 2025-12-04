module Stanton (stantonMeasure) where

stantonMeasure :: [Int] -> Int
stantonMeasure arr =
  let one = (length (filter (==1) arr)) in 
  length (filter ( == one) arr)
------------------

module Stanton (stantonMeasure) where

stantonMeasure :: [Int] -> Int
stantonMeasure arr = count (count 1)
  where count x = length $ filter (== x) arr

-------------
module Stanton (stantonMeasure) where

stantonMeasure :: [Int] -> Int
stantonMeasure = length . (filter =<< (==) . length . filter (== 1))  

  