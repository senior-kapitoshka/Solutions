module Kata where

remove :: String -> String
remove [] = []
remove str 
       | last str == '!' = remove(init str)
       | otherwise       = str

--

module Kata where

import Data.List

remove :: String -> String
remove = dropWhileEnd (== '!')

--
module Kata where

remove :: String -> String
remove str
  | last str == '!' = remove $ init str
  | otherwise = str

--

module Kata where

remove :: String -> String
remove = foldr removeMark []
  where
    removeMark '!' [] = []
    removeMark c   s  = c : s

--

module Kata where

remove :: String -> String
remove str | null str || last str /= '!' = str
           | otherwise = remove (init str)

--

module Kata where

remove :: String -> String
remove str =
  case last str of
  '!' -> remove $ init str
  _   -> str