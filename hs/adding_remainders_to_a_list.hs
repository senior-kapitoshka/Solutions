module Kata where

solve:: [Int] -> Int -> [Int]
solve xs dv = reverse(solver xs dv [])
  where 
    solver [] dv res = res
    solver (x:xs) div res
      | x<dv = solver xs dv ((x+x):res)
      | otherwise = solver xs dv ((x+(mod x dv)):res)
     

----------------
module Kata where

solve:: [Int] -> Int -> [Int]
solve xs div = map (\n -> n + mod n div) xs

-----------
