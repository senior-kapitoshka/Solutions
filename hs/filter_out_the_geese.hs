module GooseFilter where

geese = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]

gooseFilter :: [String] -> [String]
gooseFilter [] = []
gooseFilter list = filter (`notElem` geese) list

--

module GooseFilter where

geese = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]

gooseFilter :: [String] -> [String]
gooseFilter = filter (`notElem` geese)
{-

Point-free — это стиль написания функций, когда мы не указываем явно параметры (аргументы) функции. 
Вместо того чтобы писать, например:
f x = g x
Мы пишем просто:
f = g
-}


--

module GooseFilter where

import Data.List

geese = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]

gooseFilter :: [String] -> [String]
gooseFilter xs = [g | g <- xs, g `notElem` geese]


--

module GooseFilter where

geese = ["African", "Roman Tufted", "Toulouse", "Pilgrim", "Steinbacher"]

gooseFilter :: [String] -> [String]
gooseFilter [] = []
gooseFilter (x:xs)
        | any (==x) geese = gooseFilter xs
        | otherwise = x : gooseFilter xs

        ---

