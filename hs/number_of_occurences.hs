module Codewars.Occurrences where

numberOfOccurrences :: Eq a => a -> [a] -> Int
numberOfOccurrences x xs = length $ filter (\el->el==x) xs

--------------
module Codewars.Occurrences where

numberOfOccurrences :: Eq a => a -> [a] -> Int
numberOfOccurrences x = length . filter (==x)

-------------
module Codewars.Occurrences where

numberOfOccurrences :: Eq a => a -> [a] -> Int
numberOfOccurrences x xs = foldr (\t acc-> if t == x then acc + 1 else acc) 0 xs

-----------
module Codewars.Occurrences where

numberOfOccurrences :: Eq a => a -> [a] -> Int
numberOfOccurrences = (length .) . filter . (==)