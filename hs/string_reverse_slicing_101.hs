module Kata (reverseSlice) where

reverseSlice :: String -> [String]
reverseSlice str = slice (reverse str) [] 
  where
    slice str newList 
      |length str==1 = (newList++ [str])
      |otherwise = slice (tail str) (newList ++[str])

---------------------
module Kata (reverseSlice) where

import Data.List (tails)

reverseSlice :: String -> [String]
reverseSlice = init . tails . reverse

----------------
module Kata (reverseSlice) where

import Data.List (tails)

reverseSlice :: String -> [String]
reverseSlice = maybe [] (init . tails . reverse) . p
  where
    p [] = Nothing
    p xs = Just xs

----------------
module Kata (reverseSlice) where

getInits :: String -> [String]
getInits [] = []
getInits [x] = [[x]]
getInits (x:xs) = (x : xs) : getInits xs

reverseSlice :: String -> [String]
reverseSlice xs = getInits (reverse xs)