module Matryoshka where

import Data.List (sortOn,sort)

matryoshka :: [[Int]] -> Bool
matryoshka lsls = check $ sortOn head $ map sort lsls
  where
    check ([]) = True
    check (x:[]) = True
    check (x:y:xs)
      | (last y < last x) && (head x /= head y) = check (y:xs)
      | otherwise = False

-----------------
module Matryoshka where

import Data.List(sort)

matryoshka' :: [[Int]] -> Bool
matryoshka' [] = True
matryoshka' [x] = True
matryoshka' (x:y:xs)
  | (minimum x > minimum y) && (maximum x < maximum y) = matryoshka' (y:xs)
  | otherwise = False

matryoshka :: [[Int]] -> Bool
matryoshka dolls = matryoshka' sorted
  where sorted = reverse $ sort $ map sort dolls

--------------
module Matryoshka where
import Control.Arrow ((&&&))
import Data.List (sort)

matryoshka :: [[Int]] -> Bool
matryoshka dolls = all (\((a,b),(c,d)) -> a < c && b > d) $ zip ext $ drop 1 ext
  where ext = sort $ map (minimum &&& maximum) dolls

-----------------
module Matryoshka where

import Data.List (sort)

matryoshka :: [[Int]] -> Bool
matryoshka dolls = and [a < c && b > d | ((a, b), (c, d)) <- zip ms (tail ms)]
  where ms = sort $ map (\xs -> (minimum xs, maximum xs)) dolls

-------------
module Matryoshka where

import Data.List (sort)

matryoshka :: [[Int]] -> Bool
matryoshka dolls = and $ zipWith (\(a, b) (c, d) -> a < c && b > d) sorted (drop 1 sorted)
  where
    sorted = sort [(minimum x, maximum x) | x <- dolls]           