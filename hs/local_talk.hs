module Pak where

import Data.Char (isSpace)

pak :: String -> String
pak []  = ""
pak str 
  |all isSpace str = ""
  |otherwise = let insertPak str = concatMap (\i->["pak",i]) str in
                unwords ( tail (insertPak (words str)))

-------------------
module Pak where

import Data.List (intercalate)

pak :: String -> String
pak = intercalate " pak " . words

-------------
