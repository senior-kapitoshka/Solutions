module Find where

data Val = F (Int -> Bool) | I Int

instance Show Val where
  show (F a ) = "F" ++ "(Int -> Bool)" 
  show (I a ) = "I " ++ show a

используем эту функцию для поиска аноним функции -->
findF :: [Val] -> Maybe (Int -> Bool)
findF [] = Nothing
findF (x:xs) = case x of
  F f -> Just f
  _   -> findF xs

findFunction :: [Val] -> [Int] -> [Int]
findFunction func arr = case findF func of
  Just f  -> filter f arr
  Nothing -> []


  --------------
  module Find where

data Val = F (Int -> Bool) | I Int

instance Show Val where
  show (F a) = "F" ++ "(Int -> Bool)" 
  show (I a) = "I " ++ show a

findFunction :: [Val] -> [Int] -> [Int]
findFunction vals xs = foldr filter xs $ map val2func vals where
  val2func (F x) = x
  val2func _ = const True


  ------------
  module Find where

data Val = F (Int -> Bool) | I Int

instance Show Val where
  show (F a ) = "F" ++ "(Int -> Bool)" 
  show (I a ) = "I " ++ show a

findFunction :: [Val] -> [Int] -> [Int]
findFunction ((F f):_) xs = filter f xs
findFunction (_:fs) xs = findFunction fs xs

----------------
module Find where

import Data.List
import Data.Maybe

data Val = F {f :: Int -> Bool} | I Int
isF (F _) = True; isF _ = False

instance Show Val where
  show (F a ) = "F" ++ "(Int -> Bool)" 
  show (I a ) = "I " ++ show a

findFunction :: [Val] -> [Int] -> [Int]
findFunction = filter . f . fromJust . find isF

------------
