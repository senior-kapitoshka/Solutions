module LoopDetector (hasLoop) where

hasLoop :: [Int] -> Bool
hasLoop arr = check arr 0 [] 
  where
    check [] _ _ = False
    check [0] _ _ = True
    check [x] _ _ = False
    check arr idx set
      | (arr !! idx)>= length arr  = False
      | elem (arr !! idx) set = True
      | otherwise 
      = check arr (arr !! idx) (set ++ [arr!!idx])

-------------------
module LoopDetector (hasLoop) where

import Data.Vector as V
import Data.Set as S

hasLoop :: [Int] -> Bool
hasLoop = walk S.empty 0 . V.fromList
  where walk seen i xs
          | i `member` seen = True
          | otherwise       = case xs !? i of
                                Nothing -> False
                                Just j  -> walk (i `insert` seen) j xs

--------------
module LoopDetector (hasLoop) where

hasLoop :: [Int] -> Bool
hasLoop xs                        = go [] 0
  where go acc i | i `elem` acc   = True
                 | i >= length xs = False
                 | otherwise      = go (i:acc) (xs !! i)

----------------
module LoopDetector (hasLoop) where

import Data.Functor (void)

hasLoop :: [Int] -> Bool
hasLoop indices | Just _ <- foldr (const $ (=<<) $ (!?) $ indices) (Just 0) (() : void indices) = True | True = False where
  (!?) = foldr ( \ x k i -> if i == 0 then Just x else k (i-1) ) (const Nothing)

------------
module LoopDetector (hasLoop) where

import qualified Data.HashSet as HashSet

checkLoop visited [] _   _       = False
checkLoop visited xs idx len
  | idx < 0 || idx >= len        = False 
  | HashSet.member idx' visited' = True
  | otherwise                    = checkLoop visited' xs idx' len
  where idx'     = xs !! idx
        visited' = HashSet.insert idx visited

hasLoop arr = checkLoop HashSet.empty arr 0 $ length arr 

-------------
module LoopDetector (hasLoop) where

import qualified Data.IntSet as IS

hasLoop :: [Int] -> Bool
hasLoop arr = go 0 IS.empty
  where
    lg = length arr
    go i seen
      | i >= lg          = False
      | IS.member i seen = True
      | otherwise        = go (arr !! i) (IS.insert i seen)

-------------
module LoopDetector (hasLoop) where

hasLoop :: [Int] -> Bool
hasLoop arr = all (\x -> x < length arr) $ take (succ $ length arr) $ iterate (arr !!) 0      