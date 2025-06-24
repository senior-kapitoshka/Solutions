module MakeLower where

import Data.Char (toLower)

makeLowerCase :: [Char] -> [Char]
makeLowerCase [] = []
makeLowerCase (x:xs) = (toLower x): makeLowerCase xs

--

module MakeLower where

import Data.Char (toLower)

makeLowerCase :: String -> String
makeLowerCase = map toLower

--

