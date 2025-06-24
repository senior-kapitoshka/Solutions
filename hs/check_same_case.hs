module CheckSameCase (sameCase) where

import Data.Char (isAlpha,isUpper, isLower)

sameCase :: Char -> Char -> Int
sameCase l r
  |isAlpha l && isAlpha r && ((isLower l && isLower r) || (isUpper l && isUpper r))=1
  |isAlpha l && isAlpha r && not((isLower l && isLower r) || (isUpper l && isUpper r))=0
  |otherwise = -1

  --

  module CheckSameCase (sameCase) where
import Data.Char
sameCase :: Char -> Char -> Int
sameCase x y 
  | not (isLetter x) || not (isLetter y)  = -1
  | isUpper x == isUpper y = 1 
  | otherwise = 0

  --

  module CheckSameCase (sameCase) where

import Data.Char (isAlpha, isLower)

sameCase :: Char -> Char -> Int
sameCase x y
  | isAlpha x && isAlpha y = fromEnum (isLower x == isLower y)
  | otherwise = -1

  --

  module CheckSameCase (sameCase) where

import Data.Char

sameCase :: Char -> Char -> Int
sameCase a b
  | not (isAlpha a) || not (isAlpha b) = -1
  | isLower a && isLower b             = 1
  | isUpper a && isUpper b             = 1
  | otherwise                          = 0

  --

  