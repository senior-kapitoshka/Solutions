module Codewars.Strings where

import Data.Char (isLower)

lowercaseCount :: [Char] -> Int
lowercaseCount [] = 0
lowercaseCount xs = length [x | x<-xs, isLower x] 

--[x | x <- xs, isLower x] — это список только из строчных букв входной строки xs.

--length — считает длину этого списка, то есть количество строчных символов.

--

module Codewars.Strings where
import Data.Char

lowercaseCount :: [Char] -> Int
lowercaseCount = length . filter isLower

--

module Codewars.Strings where

import Text.Regex.TDFA

lowercaseCount :: [Char] -> Int
lowercaseCount = (=~ "[a-z]")

--

module Codewars.Strings where

import Data.Char

lowercaseCount :: [Char] -> Int
lowercaseCount str = length $ filter isLower str

--

lowercaseCount :: String -> Int
lowercaseCount [] = 0
lowercaseCount (x:xs)
  | isLower x = 1 + lowercaseCount xs
  | otherwise = lowercaseCount xs


--

module Codewars.Strings where

lowercaseCount :: [Char] -> Int
lowercaseCount xs = sum [1 | x <- xs, x `elem` ['a' .. 'z']]

--