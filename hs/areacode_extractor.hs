
module Kata (areaCode) where

areaCode :: String -> String
areaCode txt = find txt "" 
  where
    find [] res = res
    find (x:y:z:w:q:xs) res
      | x=='(' && q==')' = res ++ [y,z,w]
      | otherwise = find (y:z:w:q:xs) res

------------------
module Kata (areaCode) where

import Data.List.Split (splitOneOf)

areaCode :: String -> String
areaCode = (!! 1) . splitOneOf "()"

-----------------
module Kata (areaCode) where

areaCode :: String -> String
areaCode = tail . dropWhile (/= '(') . takeWhile (/= ')')
-------------------

module Kata (areaCode) where
import Data.List
import Data.Maybe

areaCode :: String -> String
areaCode text = take (b-a-1) $ drop (a+1) text
  where a = fromMaybe 0 (elemIndex '(' text)
        b = fromMaybe 0 (elemIndex ')' text)

 -------------
 module Kata (areaCode) where

import Data.Char

areaCode :: String -> String
areaCode ('(':text) = takeWhile isDigit text
areaCode text  = areaCode $ tail text

------------
module Kata (areaCode) where

areaCode :: String -> String
areaCode = tail . take 4 . dropWhile (/= '(')

      

