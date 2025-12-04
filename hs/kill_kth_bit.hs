module KillBit where

killKthBit :: Int -> Int -> Int
killKthBit n k = from (kill n k 1 []) 
  where
    kill 0 _ _ lst = lst
    kill n k cur lst
      | cur == k  = kill (div n 2) k (cur + 1) (0 : lst) 
      | otherwise = kill (div n 2) k (cur + 1) ((mod n 2) : lst)

    from = foldl (\acc bit -> acc * 2 + bit) 0

------------------
module KillBit where

import Data.Bits (clearBit)

killKthBit :: Int -> Int -> Int
killKthBit n k = clearBit n (k - 1)    