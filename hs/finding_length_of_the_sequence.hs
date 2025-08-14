module Codewars.Kata.SequenceLength (lengthOfSequence) where

import Data.List (dropWhileEnd)

lengthOfSequence :: (Eq a) => [a] -> a -> Maybe Int
lengthOfSequence lst n
  | lg>2 || lg<2  = Nothing
  | otherwise = Just(length (takeWhile (\x->x/=n) (tail (dropWhile (\x->x/=n) lst))) + 2)
    where
      lg=length (filter (\x->x==n) lst)
       
 {-
  tail берёт всё кроме первого элемента списка.

    xs = [1,2,3,4]
    tail xs
    -- [2,3,4] =>

=>  lst = [1,2,3,1]
    n = 1
    sublist = dropWhile (/= 1) lst  -- [1,2,3,1]
    tail sublist                   -- [2,3,1]
    takeWhile (/= 1) [2,3,1]      -- [2,3]
    length [2,3] + 2               -- 4

 -}      

 -------------------
 module Codewars.Kata.SequenceLength (lengthOfSequence) where

import Data.List (findIndices)

lengthOfSequence :: (Eq a) => [a] -> a -> Maybe Int
lengthOfSequence xs x = case findIndices (==x) xs of
                          [a,b] -> Just $ b - a + 1
                          _     -> Nothing

 -------------


 module Codewars.Kata.SequenceLength (lengthOfSequence) where

import Data.List (elemIndices)

lengthOfSequence xs x = 
    if length indicies /= 2 then Nothing else Just (last indicies - head indicies + 1)
    where
        indicies = elemIndices x xs                         