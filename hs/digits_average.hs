module DigitsAverage where

{-----------
    digitsAverage :: Int -> Int
    digitsAverage dig 
    | dig < 10 = dig
    | otherwise = digitsAverage (read (reduce (show dig) ""))  
        where
        reduce (x:y:zs) res 
            | mod (read [x]+ read [y]) 2==0 = reduce zs (res ++ show ( div (read [x]+ read [y]) 2))
            | otherwise = reduce zs (res ++ show ( div (read [x]+ read [y] + 1) 2))
        reduce [x] res = res ++ [x]
        reduce [] res = res 
--------------}
digitsAverage :: Int -> Int
digitsAverage x = go . digits $ x
  where
    go [x] = x
    go xs = go . zipWith (curry average) xs $ tail xs

average :: (Integral b, Integral a1, Integral a2) => (a1, a2) -> b
average (x, y) = ceiling ((fromIntegral x + fromIntegral y) / 2)

digits :: (Integral a) => a -> [a]
digits 0 = []
digits x = digits (x `div` 10) ++ [x `mod` 10]


-----------------
module DigitsAverage where

import Data.Char

digitsAverage :: Int -> Int
digitsAverage = head . until (null . tail) step . map digitToInt . show where
  step n = zipWith avg n (tail n)
  avg a b = (a + b + 1) `div` 2

  -----------
  