module CaseSensitive where

import Data.Char (isUpper)

caseSensitive :: String -> (Bool, String)
caseSensitive xs = foldl check (True, "") xs
  where
    check :: (Bool, String) -> Char -> (Bool, String)
    check (found, acc) c
      | isUpper c = (False, acc ++ [c])
      | otherwise = (found, acc )


----------
module CaseSensitive where
import Control.Arrow
import Data.Char (isUpper)

caseSensitive :: String -> (Bool,String)
caseSensitive = (null &&& id) . filter isUpper

---------
module CaseSensitive where 

import Data.Char

caseSensitive :: String -> (Bool,String)
caseSensitive = (\a -> (null a, a)) . filter isUpper

----------
module CaseSensitive where 
import Data.Char(toLower)

caseSensitive :: String -> (Bool,String)
caseSensitive xs = (xs == (map toLower xs), filter (\x -> x < 'a') xs)


---------

module CaseSensitive where 

import Data.Char (isLower)
import Control.Arrow ((&&&))

caseSensitive :: String -> (Bool, String)
caseSensitive = all isLower &&& filter (not . isLower)