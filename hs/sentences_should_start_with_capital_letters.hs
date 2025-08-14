module Fix where

import Data.List.Split (splitOn)
import Data.List (intercalate)
import Data.Char (toUpper)

fix' :: String -> String
fix' [] = []
fix' s = take (length s) (intercalate ". " (map up (splitOn ". " (s ++ ". "))))
  where
    up (x:xs)= [toUpper x] ++ xs 
    up [] = []

-----------------
module Fix where
import Data.Char
import Data.List
import Data.List.Split

fix' :: String -> String
fix' "" = ""
fix' xs = intercalate ". " . map (\(x:y) -> toUpper x : y) $ splitOn ". " xs

-----------
module Fix where

import Data.Char (toUpper)

fix' :: String -> String
fix' [] = []
fix' (x:xs) = toUpper x : go xs

go :: String -> String
go [] = []
go ('.':' ':x:xs) = '.' : ' ' : toUpper x : go xs
go (x:xs) = x : go xs

------------
module Fix where
import Data.List.Split 
import Data.Char (toUpper, isSpace)

fix' :: String -> String
fix' = unwords . map ((++".") . captialize) . filter (not . null) . splitOn "."

captialize [] = []
captialize (' ':xs) = captialize xs
captialize (x:xs) = toUpper x : xs

-------------
