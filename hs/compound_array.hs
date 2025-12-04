module Codewars.Kata.Compound where

compoundArray :: [a] -> [a] -> [a]
compoundArray [] []         = []
compoundArray (x:xs) []     = x : compoundArray xs []
compoundArray [] (y:ys)     = y : compoundArray [] ys
compoundArray (x:xs) (y:ys) = x : y : compoundArray xs ys

---------------
module Codewars.Kata.Compound where

compoundArray :: [a] -> [a] -> [a]
compoundArray xs     []     = xs
compoundArray []     ys     = ys
compoundArray (x:xs) (y:ys) = x : y : compoundArray xs ys

------------
module Codewars.Kata.Compound where

import Data.List

compoundArray :: [a] -> [a] -> [a]
compoundArray xs ys = concat $ transpose [xs, ys]

---------
module Codewars.Kata.Compound where

compoundArray :: [a] -> [a] -> [a]
compoundArray (x:xs) (y:ys) = x : y : compoundArray xs ys
compoundArray xs ys = (++) xs ys