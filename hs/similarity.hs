module Similarity where
import Data.List (intersect,union)

similarity :: ([Int],[Int]) -> Double
similarity (a, b) = fromIntegral (length (intersect a b)) / fromIntegral (length (union a b))

-------------
module Similarity where

import Data.List

similarity :: ([Int], [Int]) -> Double
similarity (xs, ys) = len (intersect xs ys) / len (union xs ys)
  where len = fromIntegral . length