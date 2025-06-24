module SeqList where

seqlist :: Int -> Int -> Int -> [Int]
seqlist f c l = take l [f, f + c ..]

--
module SeqList where

seqlist :: Int -> Int -> Int -> [Int]
seqlist first c l = take l $ iterate (+c) first

--
module SeqList where

seqlist :: Int -> Int -> Int -> [Int]
seqlist f c l = [x * c + f | x <- [0..l-1]]
--
module SeqList where

seqlist :: Int -> Int -> Int -> [Int]
seqlist _ _ 0 = []
seqlist first c l = first : seqlist (first + c) c (pred l)