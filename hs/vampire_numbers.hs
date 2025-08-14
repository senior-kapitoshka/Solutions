module Codewars.Kata.VampireNumbers where

{-import Data.List (intersect)

isVampire :: Integer -> Integer -> Bool
isVampire a b
  |(length(intersect (x) (prod)) == length (x)) && (length(intersect (y) (prod)) == length (y)) = True
  |otherwise = False
    where
      prod = show (a*b)
      x = show a
      y = show b
-}

import Data.List (sort)

isVampire :: Integer -> Integer -> Bool
isVampire a b = sort (show (a * b)) == sort (show a ++ show b)

------------
