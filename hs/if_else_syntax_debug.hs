module Grasshopper where

checkAlive :: Int -> Bool
checkAlive health =
    if health > 0
    then True
    else False

--

module Grasshopper where

checkAlive :: Int -> Bool
checkAlive = (> 0)

--

module Grasshopper where

checkAlive :: Int -> Bool
checkAlive health = (health > 0)
--

module Grasshopper where

checkAlive :: Int -> Bool
checkAlive n
  | n <= 0 = False
  | otherwise = True
--

module Grasshopper where

checkAlive :: Int -> Bool
checkAlive health = not $ health <= 0

--