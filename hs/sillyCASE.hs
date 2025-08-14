module Codewars.Kata.SillyCASE where
import Data.List
import Data.Char

sillyCASE :: String -> String
sillyCASE xs = casing $ split xs
  where
    split s = [take (div (length s + 1) 2) s,drop (div (length s + 1) 2) s]
    casing [a,b] = map toLower a ++ map toUpper b
    

    -------------

    module Codewars.Kata.SillyCASE where
import Data.Char (toLower, toUpper)

sillyCASE :: String -> String
sillyCASE xs = map toLower x ++ map toUpper y
               where p = div (1 + length xs) 2
                     x = take p xs
                     y = drop p xs

 ---------------
 module Codewars.Kata.SillyCASE where

import Data.Char

sillyCASE :: String -> String
sillyCASE xs = map toLower left ++ map toUpper right
  where (left, right) = splitAt ((length xs + 1) `div` 2) xs                    