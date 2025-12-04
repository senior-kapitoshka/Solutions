module Codewars.Kata.Divisible where

isDivisible :: Integral n => n -> [n] -> Bool
isDivisible n [] = True
isDivisible n (x:xs) 
  | mod n x == 0 = isDivisible n xs
  | otherwise = False

------------------
module Codewars.Kata.Divisible where

isDivisible :: Integral n => n -> [n] -> Bool
isDivisible n = all ((== 0) . mod n)

---------------------
module Codewars.Kata.Divisible where

isDivisible :: Integral n => n -> [n] -> Bool
isDivisible n = all (\x -> n `mod` x == 0)

----------------
