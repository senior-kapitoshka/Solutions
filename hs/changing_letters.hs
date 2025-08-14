module ChangingLetters (swap) where
import Data.Char (toUpper)

swap :: String -> String
swap str= map up str
  where 
    up :: Char-> Char
    up c 
      |c=='e'||c=='a'||c=='o'||c=='u'||c=='i' = toUpper c
      |otherwise = c

-------------
module ChangingLetters (swap) where
import Data.Char

swap :: String -> String
swap = map (\x -> if x `elem` "aeiou" then toUpper x else x)

-----------
module ChangingLetters (swap) where
import Data.Char

swap :: String -> String
swap = map (\x -> if x `elem` "aeiou" then toUpper x else x)

------------
module ChangingLetters (swap) where

import Data.Char(toUpper)

swap :: String -> String
swap xs = map f xs
  where f x = if x `elem` ['a','e','i','o','u'] then toUpper x else x

  ---------
  