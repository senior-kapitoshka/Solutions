module MakeAllNumbersNegative where

makeNegative :: [Int] -> [Int]
makeNegative= map (\x-> if x<=0 then x else x*(-1))

--------------
module MakeAllNumbersNegative where

makeNegative :: [Int] -> [Int]
makeNegative = map (negate . abs)

------------
module MakeAllNumbersNegative where

makeNegative :: [Int] -> [Int]
makeNegative l = [if  x > 0 then x * (-1) else x | x <- l]

-------------
module MakeAllNumbersNegative where

makeNegative :: [Int] -> [Int]
makeNegative (x:l)
  | x < 0 = (x:makeNegative l)
  | otherwise = (-x:makeNegative l)
  
makeNegative [] = []