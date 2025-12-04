module InverseSlicer where

inverseSlice :: [a] -> Int -> Int -> [a]
inverseSlice lst from to = fst (unzip (filter (\(x,y)-> (y<from || y>=to)) (zip lst [0..] ) ))

----------------

module InverseSlicer where

inverseSlice :: [a] -> Int -> Int -> [a]
inverseSlice l a b = take a l ++ drop b l

-----------
module InverseSlicer where

inverseSlice :: [a] -> Int -> Int -> [a]
inverseSlice xs a b = [x | (i, x) <- zip [0..] xs, i < a || i >= b]

-----------
