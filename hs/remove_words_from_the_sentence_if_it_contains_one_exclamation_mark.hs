module Kata (remove) where

import Data.List (intercalate)

remove :: String -> String
remove str = intercalate " " (filter (\s -> check s) (words str))
  where
    check s = (length (filter (\c-> c=='!') s)) /= 1

------------------
module Kata (remove) where

remove :: String -> String
remove = unwords . filter (\w->(/=1) . length $ filter (=='!') w ) . words

--------------
module Kata (remove) where

count [] _ = 0
count (x:xs) c
  | x == c = 1 + count xs c
  | otherwise = count xs c

remove s = unwords [w | w <- (words s), (count w '!' /= 1)]

------------
