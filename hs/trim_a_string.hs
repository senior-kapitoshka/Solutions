module Trim where

import Data.List (dropWhileEnd)

trim :: String -> String
trim str = let predicat = \c -> elem c " \t\n\r\f\v" in
  dropWhile (predicat) (dropWhileEnd (predicat) str)
  

  ------------
  module Trim where

import Data.List (dropWhile, dropWhileEnd)
import Data.Char (isSpace)

trim :: String -> String
trim = dropWhile isSpace . dropWhileEnd isSpace

-------
module Trim where

import Data.Text

trim :: String -> String
trim = unpack . strip . pack

--------