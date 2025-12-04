module Penultimate where

penultimate :: [a] -> a
penultimate (x:y:[]) = x
penultimate (x:y:xs) = penultimate (y:xs) 

-------------
module Penultimate where
import Data.List (init)

penultimate :: [a] -> a
penultimate = last . init

----------
module Penultimate where

penultimate :: [a] -> a
penultimate = head . tail . reverse

---------
module Penultimate where

penultimate :: [a] -> a
penultimate = fst . foldl (\(_, a) b -> (a, b)) (err, err)
  where
    err = error "penultimate: list should have at least 2 elements"
