module SF1 where

import Data.List (find)

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess lst = check lst [] []
  where
    check [] st res = res 
    check (x:xs) st res 
      |length st==0 = check xs ([x] ++ st) (res ++ [-1])
      |otherwise = check xs ([x] ++ st) (res ++ [maybe (-1) id (find (< x) st)])
      
      {-
        maybe (-1) id (find (< x) st)
          где
          -find (< x) st → Maybe Int
          -maybe (-1) id → если Nothing, вернёт -1, иначе вернёт значение.
      -}

{-

    ++ для списков в Haskell O(n) по длине левого списка.

    Это означает, что твой код имеет квадратичную сложность даже для добавления в начало/результат.

    Для добавления в начало лучше использовать ::

    x : st
    x : res
-}

module SF1 where

import Data.List (find)

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess lst = reverse (check lst [] [])
  where
    check [] st res = res 
    check (x:xs) st res 
      |length st==0 = check xs (x: st) (-1: res)
      |otherwise = check xs (x: st) ((maybe (-1) id (find (< x) st)): res)  


import Data.List (find)

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess lst = reverse (check lst [] [])
  where
    check [] _ res = res
    check (x:xs) st res
      | null st   = check xs (x : st) (-1 : res)
      | otherwise = check xs (x : st) (maybe (-1) id (find (< x) st) : res)


---------------------------
module SF1 where

import Data.List

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess xs = zipWith prevLess (inits xs) xs 
    where
        lastOrM1 [] = -1
        lastOrM1 xs = last xs
        prevLess xs x = lastOrM1 $ filter (< x) xs    
-------------------
module SF1 where

import Data.List (find,inits)
import Data.Maybe (fromMaybe)

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess = zipWith (\x -> fromMaybe (-1) . find (<x) . reverse) <*> inits

------------------
module SF1 where

f :: [Int] -> Int
f [] = -1
f [x] = -1
f (x1:x2:xs)
  | x1 > x2   = x2
  | otherwise = f (x1:xs)

arrayPreviousLess :: [Int] -> [Int]
arrayPreviousLess xs = map (\i -> f $ reverse $ take i xs) [1 .. length xs]

-------------
