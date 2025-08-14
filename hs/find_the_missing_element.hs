module MissingTree (findTheMissingTree) where

import qualified Data.Map as DICT
import Data.Maybe (listToMaybe)
import qualified Data.List as LIST

findTheMissingTree :: [Int] -> Int
findTheMissingTree trees = case listToMaybe [key|(key,value)<-DICT.toList freq, value/=commonValue] of
    Just k -> k
    Nothing -> -1
  where 
    freq = DICT.fromListWith (+) [(tree,1)|tree<-trees]
    values = DICT.elems freq
    commonValue = head (LIST.maximumBy (\a b->compare (length a) (length b))(LIST.group(LIST.sort values)))
        

---------------------
module MissingTree (findTheMissingTree) where

import Data.List(sort, group, sortOn)

findTheMissingTree :: [Int] -> Int
findTheMissingTree = head . fst . head . sortOn snd . map (\x -> (x, length x)) . group . sort

--------------------
module MissingTree (findTheMissingTree) where

import Data.List

findTheMissingTree :: [Int] -> Int
findTheMissingTree = head . head . sortOn length . reverse . group . sort