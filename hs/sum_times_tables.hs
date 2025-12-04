{-

For example, for table=[2,5], min=1, max=3 the result should be the same as

2*1 + 2*2 + 2*3 +
5*1 + 5*2 + 5*3

-}

module Codewars.Kata.Sum where

sumTimesTables :: [Integer] -> Integer -> Integer -> Integer
sumTimesTables tbl n m = foldl (\acc x->acc + sum (map (*x) [n..m]))
                          0
                          tbl 

------------------
module Codewars.Kata.Sum where

sumTimesTables :: [Integer] -> Integer -> Integer -> Integer
sumTimesTables tbl n m = sum tbl * (n+m) * (m-n+1) `div` 2

----------------
module Codewars.Kata.Sum where

sumTimesTables :: [Integer] -> Integer -> Integer -> Integer
sumTimesTables tbl n m = (sum tbl)*(sum [n..m])

--------------
module Codewars.Kata.Sum where

sumTimesTables :: [Integer] -> Integer -> Integer -> Integer
sumTimesTables tbl start end = sum [ x*i | x<-tbl, i<-[start..end] ]

------------
