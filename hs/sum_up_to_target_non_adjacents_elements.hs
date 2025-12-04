module SumUpNoAdjacents where 
sumUpNoAdjacents :: [Int] -> Int -> Bool 
sumUpNoAdjacents [] 0 = True 
sumUpNoAdjacents [] _ = False 
sumUpNoAdjacents (x:zs) dig 
  | x==dig = True 
  | otherwise = not(null zs) 
      && ( sumUpNoAdjacents (tail zs) (dig - x) || sumUpNoAdjacents zs dig)
{-
import qualified Data.Set as SET

sumUpNoAdjacents :: [Int] -> Int -> Bool
sumUpNoAdjacents list dig = cycler dig list SET.empty

cycler _ [] _ = False
cycler dig [x] _
  |x==dig = True
  |otherwise = False
cycler dig (x:y:zs) set = 
  let diff = dig - y
      newSet =  SET.insert x set
  in
      if (SET.member diff set) || (x==dig) then True
      else cycler dig (y:zs) newSet
-}
---------------------

module SumUpNoAdjacents where

sumUpNoAdjacents :: [Int] -> Int -> Bool
sumUpNoAdjacents _ 0 = True
sumUpNoAdjacents [] _ = False
sumUpNoAdjacents [x] s = x == s
sumUpNoAdjacents (x : y : xs) s = sumUpNoAdjacents xs (s - x) || sumUpNoAdjacents (y : xs) s

-----------------------
module SumUpNoAdjacents where

sumUpNoAdjacents :: [Int] -> Int -> Bool
sumUpNoAdjacents _ 0 = True
sumUpNoAdjacents [] _ = False
sumUpNoAdjacents [a] n = a == n
sumUpNoAdjacents (a:(b:t)) n = (sumUpNoAdjacents t (n-a)) || (sumUpNoAdjacents ([b]++t) n)

------------------
module SumUpNoAdjacents where

sumUpNoAdjacents :: [Int] -> Int -> Bool
sumUpNoAdjacents [] t = t == 0
sumUpNoAdjacents [x] t = x == t
sumUpNoAdjacents [x, y] t = x == t || y == t
sumUpNoAdjacents (x:xs) t = (sumUpNoAdjacents [x, (head xs)] t) || (sumUpNoAdjacents (tail xs) (t - x)) || (sumUpNoAdjacents xs t)

--------------
