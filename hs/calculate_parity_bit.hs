module CalculateParityBit (checkParity) where


checkParity :: String -> String -> Int
checkParity num bin
  | ((even (popCnt bin)) && num=="even") || ((odd (popCnt bin)) && num=="odd") 
  =  0
  | otherwise = 1

  where
    popCnt binStr = length (filter (=='1') binStr)


--------------------
module CalculateParityBit (checkParity) where

checkParity :: String -> String -> Int
checkParity parity bin =
  let bits = length $ filter (== '1') bin
      result = even bits
  in if parity == "even" && result || parity == "odd" && not result
     then 0
     else 1

-----------------------

module CalculateParityBit (checkParity) where

checkParity :: String -> String -> Int
checkParity p bin
  | even ones = if p == "even" then 0 else 1
  | otherwise = if p == "even" then 1 else 0
  where ones = length $ filter (=='1') bin

-------------
  