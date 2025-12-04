module Unpaired where

import Data.List ((\\),nub)

hotSingles :: Eq a => [a] -> [a] -> [a]
hotSingles arr1 arr2 = (a1 \\ a2) ++ (a2 \\ a1)
  where
    a1 = nub arr1
    a2 = nub arr2  

------------------

module Unpaired where

import Data.List (nub)

hotSingles :: Eq a => [a] -> [a] -> [a]
hotSingles xs ys = nub (go ys xs ++ go xs ys)
  where go vs    = filter (`notElem` vs) 

  ---------------

module Unpaired where

import Data.List ( nub )

hotSingles :: Eq a => [a] -> [a] -> [a]
hotSingles xs ys = nub $ [x | x <- xs, x `notElem` ys] <> [y | y <- ys, y `notElem` xs]

-------------

