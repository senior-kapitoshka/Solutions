module KthElement where
import Prelude hiding ((!!))

-- | Returns Just the k-th element of the list, or Nothing if k is out of bounds.
elementAt :: Int -> [a] -> Maybe a
{-
elementAt n xs 
  | n<0 || n>(length xs) = Nothing
  | otherwise= get n (zip xs [1..]) 
    where
      get n [] = Nothing
      get n ((x,y):xs)
        | n==y = Just (x)
        | otherwise = get n xs
        -}

elementAt n xs 
  | n<=0 =Nothing
elementAt _ [] = Nothing 
elementAt 1 (x:_) = Just x
elementAt n (x:xs) = elementAt (n-1) xs

-----------------------------
module KthElement where
import Prelude hiding ((!!))

-- | Returns Just the k-th element of the list, or Nothing if k is out of bounds.
elementAt :: Int -> [a] -> Maybe a
elementAt _ [] = Nothing
elementAt n (x:xs)
  | n < 1 = Nothing
  | n == 1 = Just x
  | otherwise = elementAt (n-1) xs

  ---------------
  module KthElement where
import Prelude hiding ((!!))
import Data.Maybe (listToMaybe)

elementAt :: Int -> [a] -> Maybe a
elementAt n = if n <= 0 then const Nothing else listToMaybe . drop (n - 1)

-----------
module KthElement where
import Prelude hiding ((!!))

-- | Returns Just the k-th element of the list, or Nothing if k is out of bounds.
elementAt :: Int -> [a] -> Maybe a
elementAt _ [] = Nothing
elementAt n xs
   |n <= 0 = Nothing
   |otherwise = kelem (drop (n-1) xs)
kelem :: [a] -> Maybe a
kelem [] = Nothing
kelem x = Just $ head x