module IsItWhitespace where

isItWhitespace :: Char -> Bool
isItWhitespace c 
  |c==' ' || c=='\n' || c=='\t' || c=='\r' = True
  |otherwise = False

  ------------
  module IsItWhitespace where

import Data.Char (isSpace)

isItWhitespace :: Char -> Bool
isItWhitespace = isSpace

----------
module IsItWhitespace where

isItWhitespace :: Char -> Bool
isItWhitespace = flip elem " \t\r\n"