module JoinedWords where
--import Data.List (intercalate)

joinS :: [[Char]] -> [Char] -> [Char]
--joinS a d = intercalate d a 
joinS [] _ = ""
joinS [x] _ = x
joinS (x:xs) d = x ++ d ++  joinS xs d

----
module JoinedWords where

joinS :: [[Char]] -> [Char] -> [Char]
joinS [] _ = []
joinS (x:xs) y = x ++ concatMap (y++) xs

---
module JoinedWords where

import GHC.OldList

joinS :: [[Char]] -> [Char] -> [Char]
joinS = flip intercalate

---
