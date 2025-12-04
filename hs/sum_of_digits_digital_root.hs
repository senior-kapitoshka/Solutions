module DigitalRoot where

import Data.Char (digitToInt)

digitalRoot :: Integral a => a -> a
digitalRoot x
  | x<10 = fromIntegral x
  | otherwise = digitalRoot (fromIntegral (sumOfDig x))
    where
      sumOfDig y = foldl (\acc z-> acc + (digitToInt z)) 0 (show (fromIntegral y {-:: Int-}))

-------------------
module DigitalRoot where

digitalRoot :: Integral a => a -> a
digitalRoot 0 = 0
digitalRoot n = 1 + (n - 1) `mod` 9

------------------
module DigitalRoot where

import Data.Char

toDigits n
    | n < 0 = error "Negative number!"
    | n == 0 = [0]
    | otherwise = map toInteger (map digitToInt $ show n)

digitalRoot n 
    | n < 10 = n
    | otherwise = digitalRoot (sum $ toDigits n)

----------------
module DigitalRoot where

digitalRoot :: Integer -> Integer
digitalRoot x
  | x < 0 = error "digitalRoot: number must be >= 0"
  | x < 10 = x
  | otherwise = digitalRoot $! sum (map (read . (:[])) (show x))

-------------
      