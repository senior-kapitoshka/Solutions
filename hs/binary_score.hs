--fail random tests
module Kata.BinaryScore where

import Data.Bits ( (.|.) )
score :: Integer -> Integer
score n = foldl1 (.|.) [0..n]

{-module Kata.BinaryScore where

import Data.Bits (shiftL, shiftR)

score :: Integer -> Integer
score 0 = 0
score n = (1 `shiftL` highestBit n) - 1

highestBit :: Integer -> Int
highestBit x = go x 0
  where
    go 0 acc = acc
    go y acc = go (y `shiftR` 1) (acc + 1)
-}

--
module Kata.BinaryScore where
import Data.Bits

score :: Integer -> Integer
score = subtract 1 . shiftL 1
      . ceiling . logBase 2
      . fromIntegral . succ

 --

 module Kata.BinaryScore where

score :: Integer -> Integer
score 0 = 0
score n = score (n `div` 2) * 2 + 1

--

