module SetReducer (setReducer) where

setReducer :: [Int] -> Int
setReducer lst
  | length lst == 1 = head lst
  | otherwise = setReducer (reduce lst [] [])
  where
    reduce [] stack res = reverse ((length stack) : res)
    reduce (x:xs) stack res
      | null stack = reduce xs [x] res
      | head stack == x = reduce xs (x:stack) res
      | otherwise       = reduce xs [x] ((length stack) : res)

---------------------
module SetReducer (setReducer) where
import Data.List (group)

setReducer :: [Int] -> Int
setReducer xs
  | length xs == 1 = head xs
  | otherwise      = setReducer (map length (group xs))


--------------------

module SetReducer (setReducer) where

import Data.List (group)

setReducer :: [Int] -> Int
setReducer [x] = x
setReducer xs = (setReducer . map length . group) xs

-----------------
module SetReducer (setReducer) where

import Data.List (group)

setReducer :: [Int] -> Int
setReducer xs =
  case map length (group xs) of
    [x] -> x
    ys  -> setReducer ys

-------------------
module SetReducer (setReducer) where
import Data.List

setReducer :: [Int] -> Int
setReducer a | length a == 1 = head a
             | otherwise = setReducer $ map length (group a)