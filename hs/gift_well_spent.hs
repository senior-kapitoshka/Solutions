module Gift where
import qualified Data.Map as Map

import Data.List (find)
import Data.Maybe (listToMaybe)

buy :: (Eq a, Num a) => a -> [a] -> Maybe (Int, Int)
buy x arr = listToMaybe
  [ (i, j)
  | i <- [0 .. length arr - 2]
  , j <- [i + 1 .. length arr - 1]
  , arr !! i + arr !! j == x
  ]

  --
  module Gift where
import Data.Maybe

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy c is = listToMaybe [ (x, y) | x <- [0..n - 2], y <- [x + 1..n - 1], (is !! x) + (is !! y) == c ]
             where n = length is


           --

module Gift where

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy c is = headMay possibilities
  where
    indexed = zip is [0..]
    possibilities = [(y, y') | (x, y) <- indexed, (x', y') <- indexed, y < y', x + x' == c]
    headMay [] = Nothing
    headMay xs = Just $ head xs

--

module Gift where
import Data.List (findIndex)
import Control.Applicative ((<|>), (<$>))

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy c is = go is 0
  where go [] _     = Nothing
        go (i:is) n = (\x -> (n,x+n+1)) <$> findIndex ((==c).(+i)) is
                     <|> go is (n + 1)

--

module Gift where

import Data.Maybe

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy n xs = listToMaybe [(i,j) | (i,x) <- zip [0..] xs, (j,y) <- zip [0..] xs, i < j, x + y == n]

--


module Gift where
import Data.Maybe


buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy c is = listToMaybe [(i,j)|(i,a)<-idx, (j,b)<-idx, i<j, a+b == c]
  where idx = zip [0..] is

--

module Gift where
import Data.List (elemIndex)

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy = buy' 0
  where buy' _ _ [] = Nothing
        buy' i c (x:xs) = case elemIndex (c-x) xs of
                            Nothing -> buy' (i+1) c xs
                            Just i' -> Just (i, i+1+i')
                      

--

module Gift where

import Data.List (elemIndex)

buy :: (Num a, Eq a) => a -> [a] -> Maybe (Int, Int)
buy c [] = Nothing
buy c (x:xs) = case elemIndex (c - x) xs of
  (Just i) -> Just (0, i + 1)
  Nothing -> case buy c xs of
               (Just (a, b)) -> Just (a + 1, b + 1)
               Nothing       -> Nothing
