module Kata (freqSeq) where

import qualified Data.Map as MAP
import Data.List (intercalate)

freqSeq :: String -> Char -> String
freqSeq str sep = intercalate [sep] [show (freq MAP.!char) | char<-str]
  where
    freq = MAP.fromListWith (+) [(char,1)|char<-str]
    

----

module Kata (freqSeq) where

import Data.List

count x = show . length . filter (x ==)

freqSeq :: String -> Char -> String
freqSeq str sep = intercalate [sep] $ map (\c -> count c str) str

---

module Kata (freqSeq) where
import Data.List

freqSeq :: String -> Char -> String
freqSeq str sep = intersperse sep sTn
  where sTn = map (head . show . length . (\x -> filter (==x) str)) str

---
module Kata (freqSeq) where

import qualified Data.Map as Map
import Data.Maybe (fromMaybe)
import Data.List (intersperse)

freqSeq :: String -> Char -> String
freqSeq str sep =
  let charFreqMap = Map.fromListWith (+) [(c, 1) | c <- str]
      freqStr     = [fromMaybe 0 (Map.lookup c charFreqMap) | c <- str]
  in concat $ intersperse [sep] (map show freqStr)

----

module Kata (freqSeq) where

import Data.List

freqSeq :: String -> Char -> String
freqSeq str sep = intersperse sep $ concatMap freq str
  where freq c = show . length $ filter (== c) str 

         