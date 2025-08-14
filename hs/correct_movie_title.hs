module MovieTitle where
import Data.List (intercalate)
import Data.List.Split (splitOn)
import Data.Char (toUpper,toLower)

correctMovieTitle :: String -> String
correctMovieTitle "" = ""
correctMovieTitle s = intercalate " " $ map capFirst $ splitOn " " s
  where capFirst :: String -> String
        capFirst "" = ""
        capFirst (x:xs) = toUpper x : map toLower xs
 

 ---

 module MovieTitle where
import Data.Char(toLower, toUpper)

correctMovieTitle :: String -> String
correctMovieTitle = unwords . map (\(x:xs) -> toUpper x : map toLower xs) . words


----
module MovieTitle where

import Data.Char

correctMovieTitle :: String -> String
correctMovieTitle = unwords . map ucFirst . words
  where ucFirst = zipWith ($) (toUpper : repeat toLower)

  ----

  module MovieTitle where

import Data.Char

correctMovieTitle :: String -> String
correctMovieTitle = unwords . map capitalize . words where
  capitalize [] = []
  capitalize (h:t) = toUpper h : map toLower t