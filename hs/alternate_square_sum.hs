module Codewars.Exercises.Alternate where
import Data.Maybe (listToMaybe)

alternateSqSum :: [Integer] -> Maybe Integer
alternateSqSum seq 
  |length seq == 0 = Nothing
  |otherwise = Just(foldl (\sum (i,d)-> if mod i 2 == 0 then sum+d^2 else sum+d ) 0 (zip [1..] seq))

--------------
module Codewars.Exercises.Alternate where
import Data.Maybe (listToMaybe)

alternateSqSum :: [Integer] -> Maybe Integer
alternateSqSum [] = Nothing
alternateSqSum xs = Just . sum . map (\(f, x) -> f x) . zip (cycle [id, (^2)]) $ xs

-------------
module Codewars.Exercises.Alternate where
import Data.Maybe (listToMaybe)

alternateSqSum :: [Integer] -> Maybe Integer
alternateSqSum = listToMaybe . scanr1 (+) . zipWith ($) (cycle [id, (^2)])

----------
module Codewars.Exercises.Alternate where
import Data.Maybe (listToMaybe)

alternateSqSum :: [Integer] -> Maybe Integer
alternateSqSum [] = Nothing
alternateSqSum lst = Just . sum $ zipWith (\a b -> if odd b then a else a^2) lst [1..]

--------
module Codewars.Exercises.Alternate where

mapCyclic = zipWith id . cycle
square2 = mapCyclic [id, (**2)]

alternateSqSum :: [Double] -> Maybe Double
alternateSqSum []  = Nothing
alternateSqSum seq = Just . sum . square2 $ seq