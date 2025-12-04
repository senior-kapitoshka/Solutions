module DuplicateArguments (solution) where

import Data.List (nub)

solution :: (Eq a,Ord a) => [a] -> Bool
solution lst
  | length (nub lst) == length lst = False
  | otherwise = True

-------------
module DuplicateArguments (solution) where

import Data.List(nub)

solution :: (Eq a,Ord a) => [a] -> Bool
solution = (/=) <*> nub

-----------
module DuplicateArguments (solution) where
import Data.Set
solution :: (Eq a,Ord a) => [a] -> Bool
solution [] = False
solution (x:xs) = elem x xs || solution xs

---------
module DuplicateArguments (solution) where

import Data.List (group, sort)

solution :: (Eq a,Ord a) => [a] -> Bool
solution = any (>1) . map length . group . sort