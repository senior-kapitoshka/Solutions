module SimpleFibStrings where 

solve :: Int -> String
solve 0 = "0"
solve 1 = "01"
solve n = solver n "" 0
  where 
    solver n res cnt
      | cnt == n = res
      | otherwise = solver n ((solve (n-1))++(solve (n-2))) (cnt+1) 

------------
module SimpleFibStrings where 

solve :: Int -> String
solve 0 = "0"
solve 1 = "01"
solve n = solve (n-1) ++ solve (n-2)
-------------
module SimpleFibStrings where

fibo :: [String]
fibo = "0" : "01" : zipWith (++) (tail fibo) fibo

solve :: Int -> String
solve = (fibo !!)

-----------
module SimpleFibStrings where 

solve :: Int -> String
solve = (fibs !!)
  where fibs = "0" : scanl (++) "01" fibs

  --------------

  
