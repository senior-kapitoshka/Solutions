module Operation (result) where

result :: [[Int]] -> Int
result xss = foldl (*) 1 (map (foldl (+) 0) xss)

---------------
module Operation (result) where

result :: [[Int]] -> Int
result = product . map sum

-------------
module Operation (result) where

result :: [[Int]] -> Int
result x =  product (map sum x)

-------------
module Operation (result) where

result :: [[Int]] -> Int
result n = prod (sm n)
  where
  sm n = map sum n
  prod [] = 1
  prod (x:xs) = x * prod xs