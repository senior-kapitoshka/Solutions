module StringScramble (scramble) where

import Data.List (sortBy)
import Data.Ord (comparing)

scramble :: String -> [Int] -> String
scramble str ids = map (\(k,v)-> v) (sortBy (comparing fst) (zip ids str))


-----------
module StringScramble (scramble) where

import Data.List


scramble :: String -> [Int] -> String
scramble s = map fst . sortOn snd . zip s

--------
module StringScramble (scramble) where

import Data.List

scramble :: String -> [Int] -> String
scramble xs is = map snd $ sort $ zip is xs

---------
