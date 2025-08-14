module Average where

import Data.List (transpose)

avgArray :: [[Int]] -> [Double]
avgArray arr = map average (transpose arr)
  where 
    average column = fromIntegral(sum column)/ fromIntegral(length column)

------
module Average where

import Data.List (transpose)

avgArray :: [[Int]] -> [Double]
avgArray = map mean . transpose

mean :: [Int] -> Double
mean [] = 0
mean xs = (fromIntegral $ sum xs) / (fromIntegral $ length xs)

----
