module Sliding where

sliding :: [Int] -> Int -> [Int]
sliding lst k
  | k == 1            = lst
  | k > length lst    = []
  | k == length lst   = [maximum lst]
  | otherwise         = wind lst k [] []
  where
    wind [] _ _ res = reverse res

    wind (x:xs) k temp res
      | length temp == k-1 =
          let window = x : temp
          in wind xs k (init window) (maximum window : res)

      | otherwise =
          wind xs k (x : temp) res
-------------------
module Sliding where

import Data.List.Split

sliding :: [Int] -> Int -> [Int]
sliding xs n = map maximum $ divvy n 1 xs
{-
divvy — это функция из пакета Data.List.Split,
которая разбивает список на перекрывающиеся
или неперекрывающиеся окна (срезы) заданного
размера и с заданным шагом.

-}


------------
module Sliding where
import Data.List

sliding :: [Int] -> Int -> [Int]
sliding xs n = map (maximum . take n) $ zipWith const (tails xs) $ drop (pred n) xs

-----------
module Sliding where

sliding :: [Int] -> Int -> [Int]
sliding [] _ = []
sliding nums@(_:xs) n
  | length nums < n = []
  | otherwise = (maximum $ take n nums) : sliding xs n

------------
