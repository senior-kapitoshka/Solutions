module SwapHeadTail where

swapHeadAndTail :: [Int] -> [Int]
swapHeadAndTail xs = tail' ++ mid ++ head'
  where
    (head',rest)= splitAt (div (length xs) 2) xs
    (mid, tail') =splitAt (mod (length xs) 2) rest

    ------------------
    