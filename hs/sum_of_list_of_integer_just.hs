module SumOfJusts where

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts lst = foldl step (Just 0) lst
  where
    step (Just acc) (Just x) = Just (acc + x)
    step _ _                 = Nothing

----------------------
module SumOfJusts where

sumJusts :: [Maybe Integer] -> Maybe Integer

sumJusts = fmap sum . sequence

----------
module SumOfJusts where

sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts xs = sum <$> sequence xs

--------------
module SumOfJusts where
import Data.Maybe
sumJusts :: [Maybe Integer] -> Maybe Integer
sumJusts x = listToMaybe ((sum (map fromJust x)):[])