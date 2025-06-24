module PriceOfMango where

mango :: Int -> Int -> Int
mango 0 p = 0
mango q 0 = 0
mango q p = q*p-((div q 3)*p)

--
module PriceOfMango where

mango :: Int -> Int -> Int
mango = (*) . ceiling . (2/3*) . fromIntegral

---
module PriceOfMango where

mango :: Int -> Int -> Int
mango = (*).((-)<*>(`div`3))

--

