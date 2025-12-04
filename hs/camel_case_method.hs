module CamelCase.JorgeVS.Kata where
import Data.Char (toUpper)
import Data.List (intercalate)
camelCase :: String -> String
camelCase x = intercalate "" ( map (\(x:xs)->toUpper x :xs) (words x))

---------------
module CamelCase.JorgeVS.Kata where

import Data.Char (toUpper)

camelCase :: String -> String
camelCase = concatMap (\(x:xs) -> toUpper x:xs) . words

--------------
module CamelCase.JorgeVS.Kata where

import Control.Lens (_head, over)
import Data.Char (toUpper)

camelCase :: String -> String
camelCase = concatMap (over _head toUpper) . words

-------------
module CamelCase.JorgeVS.Kata where

import Data.Char
import Control.Lens

camelCase :: String -> String
camelCase x = (_head %~ toUpper) =<< (words x)

------------
module CamelCase.JorgeVS.Kata where
import Data.Char

{-
    В do записи для списка <- извлекает каждый элемент по очереди.

    do
    x <- [1,2,3]
    return (x*2)
    Интерпретируется как [2,4,6].
-}
camelCase :: String -> String
camelCase s = do
  x:xs <- words s
  toUpper x:xs

-----------
  