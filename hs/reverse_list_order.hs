module Codewars.Kata.Reverse where

reverseList :: [a] -> [a]
reverseList []= []
reverseList a = reverse a
reverseList (x:xs) = reverseList xs ++ [x]

--

module Codewars.Kata.Reverse where

reverseList :: [a] -> [a]
reverseList = reverse