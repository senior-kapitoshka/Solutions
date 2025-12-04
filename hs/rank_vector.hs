module RankVector where

import Data.List (sort)

ranks :: (Eq a, Ord a) => [a] -> [Int]
ranks lst = sortAndRank (zip [1..] (reverse (sort lst))) lst []
  where
    sortAndRank [] _ res = res
    sortAndRank _ [] res = res
    sortAndRank sortList (x:xs) res = sortAndRank sortList xs (res++[findId x sortList 0])
      where
        findId :: Eq a => a -> [(Int,a)] -> Int -> Int
        findId i [] idx = idx
        findId i (x:xs) idx
          | i == (snd x) = fst x
          | otherwise = findId i xs idx

-------------------
module RankVector where
import Data.List
import Data.Maybe

ranks :: (Eq a, Ord a) => [a] -> [Int]
ranks xs = map (succ . fromJust . flip elemIndex sortd) xs
  where sortd = reverse $ sort xs

{-

map (succ . fromJust . flip elemIndex sortd) xs

Берём каждый элемент x из исходного списка xs.

Находим его индекс в отсортированном по убыванию списке (flip elemIndex sortd x) → Maybe Int

Превращаем Maybe Int в Int через fromJust

Прибавляем 1 через succ

В итоге получаем ранг элемента, где 1 — наибольший элемент, 2 — следующий и т.д.
-}  

------------
module RankVector where

import Data.Maybe (fromJust)
import Data.List (sort)

ranks :: (Eq a, Ord a) => [a] -> [Int]
ranks xs = map (fromJust . flip lookup ranked) xs
  where ranked = (`zip` [1..]) $ reverse $ sort xs
------------
module RankVector where

ranks :: (Eq a, Ord a) => [a] -> [Int]
ranks l = map (\ x -> (+1) . length $ filter (> x) l) l

-------------
module RankVector where
import Data.List

ranks :: (Eq a, Ord a) => [a] -> [Int]
ranks list = map rank list
  where rank n = succ . length $ filter (n<) list