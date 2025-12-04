module Kata (lowestTemp) where


lowestTemp :: String -> Maybe Int
lowestTemp t 
  | length t == 0 = Nothing
  | otherwise = Just(minimum (map read (words t)))

  ---------------
  module Kata (lowestTemp) where

import Data.List (sort)
import Data.Maybe (listToMaybe)

lowestTemp :: String -> Maybe Int
lowestTemp = listToMaybe . sort . map read . words

--------------
module Kata (lowestTemp) where

lowestTemp :: String -> Maybe Int
lowestTemp [] = Nothing
lowestTemp xs = Just $ minimum $ map read $ words xs

-------------
module Kata (lowestTemp) where

lowestTemp :: String -> Maybe Int
lowestTemp = go . map read . words
  where go [] = Nothing
        go xs = Just $ minimum xs