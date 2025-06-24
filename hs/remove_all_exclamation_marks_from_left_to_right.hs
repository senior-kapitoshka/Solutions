module Kata (remove) where

remove :: String -> Int -> String
remove str 0 = str
remove [] _ = []
remove (x:xs) n
  | ( n>0 && x=='!') = remove xs (n-1)
  | otherwise  = x : remove xs n

  --

  module Kata (remove) where

remove :: String -> Int -> String
remove xs       0 = xs
remove []       _ = []
remove ('!':xs) n = remove xs (n-1)
remove (x:xs) n   = x : remove xs n

--

module Kata (remove) where
import Data.List

remove :: String -> Int -> String
remove str n = str \\ (replicate n '!')

--

module Kata (remove) where

remove :: String -> Int -> String
remove s 0 = s
remove [] _ = []
remove s@(h:t) n
  | h == '!' = remove t (n - 1)
  | otherwise = h : remove t n

  --

  module Kata (remove) where

import Data.List (delete)

remove :: String -> Int -> String
remove s n = iterate (delete '!') s !! n

--

module Kata (remove) where

import Data.List

remove :: String -> Int -> String
remove = (. flip replicate '!') . (\\)