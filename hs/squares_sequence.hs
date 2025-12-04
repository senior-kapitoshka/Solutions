module Codewars.Exercise.Squares where

squares :: Integer -> Int -> [Integer]
squares x n  
  |n<=0 = []
  |otherwise = map (\(x,y)->x^y) (zip (repeat x) [2^i | i <- [0..n-1]]) 

  -----------------
  module Codewars.Exercise.Squares where

squares :: Integer -> Int -> [Integer]
squares x n = take n $ iterate (^2) x

--------------
module Codewars.Exercise.Squares where

squares :: Integer -> Int -> [Integer]
squares x n 
  | n <= 0 = []
  | otherwise = x : squares (x ^ 2) (n - 1)