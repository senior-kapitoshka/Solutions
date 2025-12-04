module DivisibleByThree where

import Data.Char (digitToInt)

divisibleByThree :: String -> Bool
divisibleByThree str
  | mod (check str) 3 == 0 = True
  | otherwise = False
    where
      check str = foldl (\acc x->acc+(digitToInt(x))) 0 str 

------------------
module DivisibleByThree where
import Data.Char

divisibleByThree :: String -> Bool
divisibleByThree = (== 0) . (flip mod 3) . sum . map digitToInt

 -------------
 module DivisibleByThree where

import Data.Char (digitToInt)

divisibleByThree :: String -> Bool
divisibleByThree s = (sum $ map digitToInt s) `mod` 3 == 0

-------------
module DivisibleByThree where

divisibleByThree :: String -> Bool
divisibleByThree s = read s `mod` 3 == 0

--------------
module DivisibleByThree where
import Data.Char

divisibleByThree :: String -> Bool
divisibleByThree [d] = elem d "369"
divisibleByThree s = divisibleByThree . show . sum $ map digitToInt s
