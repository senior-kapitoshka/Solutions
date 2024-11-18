module RemoveDuplicates  where

import Data.List (nub);

distinct :: [Int] -> [Int]
distinct l = nub(l);

////////////////

module RemoveDuplicates  where
import Data.List

distinct :: [Int] -> [Int]
distinct = nub

//////////////
module RemoveDuplicates  where

distinct :: [Int] -> [Int]
distinct [] = []
distinct (x:xs) = x : distinct (filter (/=x) xs)

//////////////
module RemoveDuplicates  where

data Tree a = Node (Tree a) (Tree a) a | Leaf

insert :: Ord a => a -> Tree a -> Maybe (Tree a)
insert x Leaf                = Just (Node Leaf Leaf x)
insert x (Node left right y)
  | x == y    = Nothing
  | x < y     = fmap (\left' -> Node left' right y) (insert x left)
  | otherwise = fmap (\right' -> Node left right' y) (insert x right)

distinct' :: Ord a => Tree a -> [a] -> [a]
distinct' _    []       = []
distinct' seen (x : xs) = case (insert x seen) of
  Nothing    -> distinct' seen xs
  Just seen' -> x : distinct' seen' xs

distinct :: [Int] -> [Int]
distinct = distinct' Leaf

/////////////
module RemoveDuplicates  where

import qualified Data.IntSet as IntSet

distinct :: [Int] -> [Int]
distinct = go IntSet.empty
  where
    go _ []       = []
    go s (x:xs)
      | IntSet.member x s = go s xs
      | otherwise         = x : go (IntSet.insert x s) xs

