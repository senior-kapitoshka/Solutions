module Stones (solution) where

solution :: String -> Int
solution str = check str 0
  where
    check [] res = res
    check [x] res = res
    check (x:y:xs) res
      | x==y = check (y:xs) (res+1)
      | otherwise = check (y:xs) res

----------------
module Stones (solution) where

import Data.List (group)

solution :: String -> Int
solution s = length s - length (group s)

-----------
module Stones (solution) where


solution :: String -> Int
solution ""     = 0
solution (x:"") = 0
solution (x:y:xs)
    | x == y    = 1 + solution (y:xs)
    | otherwise = 0 + solution (y:xs)

--------------
module Stones (solution) where

import Data.List (group)

solution :: String -> Int
solution = sum . map (pred . length) . group

-----------
module Stones (solution) where


solution :: String -> Int
solution [] = 0
solution [x] = 0
solution (x:y:xs)
    | x == y = 1 + solution(y:xs)
    | otherwise = solution(y:xs)