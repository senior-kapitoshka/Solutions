module OnesAndZeroes (sameLength) where

import Data.List (group)

sameLength :: String -> Bool
sameLength s = check (group s)
  where
    check [] = True
    check [x] = False
    check (x:y:zs)
      |(length x==length y) && (head x=='1' && head y=='0') = check zs
      |otherwise = False

---------------------
module OnesAndZeroes (sameLength) where

import Data.List (group)
import Data.List.Split (divvy)

sameLength :: String -> Bool
sameLength s = head s == '1' && even (length gs) && all (\[a, b] -> a == b) (divvy 2 2 gs)
  where
    gs = map length $ group s

------------------
module OnesAndZeroes (sameLength) where

import Data.List (group)

sameLength :: String -> Bool
sameLength = go 0 . group
  where
        go n []               = n == 0
        go n (xs@('0':_):xss) = n == length xs && go 0 xss
        go n (xs@('1':_):xss) = go (length xs) xss

 ------------------
 module OnesAndZeroes (sameLength) where

sameLength :: String -> Bool
sameLength [] = True
sameLength s
  | length ones == length zeros = sameLength rest
  | otherwise                   = False
  where
    (ones, r0)    = span (=='1') s
    (zeros, rest) = span (=='0') r0                 