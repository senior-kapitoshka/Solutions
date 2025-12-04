module FromToStepGenerator where

generator :: Integer -> Integer -> Integer -> [Integer]
generator f t s
  | s == 0 = []
  | f < t = [f,f+s..t]
  | otherwise = [f,f-s..t]

  ------------
  