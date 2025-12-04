module ConsecutiveDifferences (differences) where

differences :: [Int] -> Int
differences list
  |length list == 1 = head list
  |otherwise = differences (fld list [])
    where
      fld [] newList = newList
      fld (x:y:xs) newList = fld (y:xs) (newList ++ [abs (x-y)])
      fld (x:_) newList = newList
      
---------------
module ConsecutiveDifferences (differences) where

differences :: [Int] -> Int
differences [x] = x
differences x = differences (zipWith (\x y -> abs(x - y)) x (tail x))

-----------
module ConsecutiveDifferences (differences) where

differences :: [Int] -> Int
differences [x] = x
differences xs = differences $ zipWith (\x y -> abs (x-y)) xs (drop 1 xs)

-----------



----------------
module ConsecutiveDifferences (differences) where

differences :: [Int] -> Int
differences [x] = x
differences xs = differences $ zipWith ((abs .).(-)) (drop 1 xs) xs

---------------
module ConsecutiveDifferences (differences) where

differences :: [Int] -> Int
differences [x] = x
differences  xs = differences (zipWith ((abs .) . subtract) xs (tail xs))

------------
