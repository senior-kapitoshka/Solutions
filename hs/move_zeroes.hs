module MoveZeroes where

import Data.List (partition)

move_zeroes :: Bool -> [Int] -> [Int]
move_zeroes isRight xs =  
  let (zs, oth) = partition (\x-> x==0) xs in
    if isRight then oth ++ zs
    else zs ++ oth

------------
module MoveZeroes where
import Data.List

move_zeroes :: Bool -> [Int] -> [Int]
move_zeroes False = uncurry (++) . partition (== 0)
move_zeroes True  = uncurry (++) . partition (/= 0)

----------
module MoveZeroes where

import Data.List

move_zeroes :: Bool -> [Int] -> [Int]
move_zeroes isRight = sortOn ((==isRight) . (<=0))

---------
module MoveZeroes where

move_zeroes :: Bool -> [Int] -> [Int]
move_zeroes True xs = (non_zeros xs) ++ (zeros xs)
move_zeroes False xs = (zeros xs) ++ (non_zeros xs)

zeros xs = [x | x <- xs, x == 0]
non_zeros xs = [x | x <- xs, x /= 0]