module DropFromEnd (dropFromEnd) where

dropFromEnd :: Int -> [a] -> [a]
dropFromEnd n lst = zipWith const lst (drop n lst)

{-

    lst =       [a, b, c, d, e, f]
    drop 2 lst =          [c, d, e, f]
    zipWith const делает:

    zipWith const
    [a, b, c, d, e, f]
    [c, d, e, f]

-}

-------------
{-# Language ParallelListComp #-}

module DropFromEnd (dropFromEnd) where

dropFromEnd :: Int -> [a] -> [a]
dropFromEnd n xs = [ x | x <- xs | _ <- drop n xs ]
-------------------
module DropFromEnd (dropFromEnd) where

dropFromEnd :: Int -> [a] -> [a]
dropFromEnd n xs
 | n <= 0 = xs
 | otherwise = next (drop n xs) (take n xs) where
    next xs rs
     | length (take n xs) < n = take (length (take n xs)) rs
     | otherwise = rs ++ next (drop n xs) (take n xs)
