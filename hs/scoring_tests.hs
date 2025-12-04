module Codewars.Kata.ScoringTests where

scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
scoreTest li a b c = calc li 0 0 0 a b c
  where
    calc [] corr om wr a b c = corr*a + om*b - wr*c
    calc (x:xs) corr om wr a b c 
      | x==0 =  calc xs (corr+1) om wr a b c
      | x==1 =  calc xs corr (om+1) wr a b c
      | otherwise = calc xs corr om (wr+1) a b c

 {-----------------
 --scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
--scoreTest li a b c = corr * a + om * b + wr * c
  --where
    --(corr, om, wr) = foldl count (0, 0, 0) li
    --count (c1, o1, w1) x
      --| x == 0    = (c1+1, o1, w1)
      --| x == 1    = (c1, o1+1, w1)
      --| otherwise = (c1, o1, w1+1)
------------------}     

module Codewars.Kata.ScoringTests where

scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
scoreTest li a b c = sum $ map (([a, b, -c] !!) . fromIntegral) li

-------------------
module Codewars.Kata.ScoringTests where

scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
scoreTest li a b c = sum $ map (\x -> case x of
                                  0 -> a
                                  1 -> b
                                  2 -> -c) li

--------------

module Codewars.Kata.ScoringTests where

scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
scoreTest li a b c = sum ([a | i <- li, i == 0] ++ [b | i <- li, i == 1] ++ [-c | i <- li, i == 2])

----------
-- Solved by Gemini 2.0 Pro
module Codewars.Kata.ScoringTests where

scoreTest :: (Integral a) => [a] -> a -> a -> a -> a
scoreTest li a b c = foldl (\acc x -> case x of
                                    0 -> acc + a
                                    1 -> acc + b
                                    2 -> acc - c
                                    _ -> acc) 0 li


------

