module GridMap where

gridMap :: (a -> b) -> [[a]] -> [[b]]
gridMap f xss = map (map f) xss

-----------
module GridMap where

gridMap :: (a -> b) -> [[a]] -> [[b]]
gridMap = map.map

---------
module GridMap where

gridMap :: (a -> b) -> [[a]] -> [[b]]
gridMap = map <$> map

---------
module GridMap where

gridMap :: (a -> b) -> [[a]] -> [[b]]
gridMap f xss = map (\x -> map (\y -> f y) x) xss