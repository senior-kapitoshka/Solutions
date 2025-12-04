module SingleDigit (singleDigit) where
import Data.Bits (popCount) ------------------- count of 1 bits in a binary representation

singleDigit :: Integer -> Int
singleDigit n
  | n <= 9    = fromInteger n
  | otherwise = singleDigit ( toInteger ( popCount ( n)))

  -----------------

  module SingleDigit (singleDigit) where

import Data.Bits (popCount)

singleDigit :: Integer -> Int
singleDigit = fromIntegral . until (< 10) (fromIntegral . popCount)

--------------
