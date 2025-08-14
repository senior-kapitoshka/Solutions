module Kata (seaSick) where

seaSick :: String -> String
seaSick sea 
  |cnt==0 || (fromIntegral (length sea) / fromIntegral cnt) >=5 ="No Problem"
  |otherwise = "Throw Up"
    where 
      cnt = length (filter check (zip sea (tail sea)))
      check (a,b) = (a=='~' && b=='_') || (a=='_' && b=='~')
      

-----------
module Kata (seaSick) where

import Data.List (group)

seaSick :: String -> String
seaSick s = if (<= length s) . (*5) . pred . length . group $ s then "No Problem" else "Throw Up"

---------
module Kata (seaSick) where

seaSick :: String -> String
seaSick sea = go sea 0
  where go ('~':'_':xs) c = go ('_':xs) (c+1)
        go ('_':'~':xs) c = go ('~':xs) (c+1)
        go (a:b:xs) c = go (b:xs) c
        go _ c = if c*5 > length sea then "Throw Up" else "No Problem"

-------------

module Kata (seaSick) where

import Data.List

seaSick :: String -> String
seaSick sea
  | fromIntegral altCount / fromIntegral (length sea) > 0.2 = "Throw Up"
  | otherwise = "No Problem"
  where
    altCount = length $ filter (\(a, b) -> a /= b) (zip sea (tail sea))