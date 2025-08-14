module Codewars.Kata.Comparator where

import Data.List (intersect)

matchList :: Eq a => [a] -> [a] -> Int
matchList xs ys = length $ intersect xs ys

----------

module Codewars.Kata.Comparator where

matchList :: Eq a => [a] -> [a] -> Int
matchList xs ys = sum [1 | x <- xs, elem x ys]

---------
module Codewars.Kata.Comparator where
import Data.List

matchList :: Eq a => [a] -> [a] -> Int
matchList xs ys = length $ filter(\x -> elem x ys) xs

----------

module Codewars.Kata.Comparator where

import Data.List

matchList :: Eq a => [a] -> [a] -> Int
matchList = (length .) . intersect

-----------

module Codewars.Kata.Comparator where
import Data.List (intersect)

matchList :: Eq a => [a] -> [a] -> Int
matchList = ((.).(.)) length intersect

--------
module Codewars.Kata.Comparator where

matchList :: Eq a => [a] -> [a] -> Int
matchList [] _ = 0
matchList (x:xs) ys
  | x `elem` ys = 1 + matchList xs ys
  | otherwise   = matchList xs ys

  -------------
