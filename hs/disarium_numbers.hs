module Disarium where

disariumNumber :: Int -> String
disariumNumber n 
  |n == dis n =  "Disarium !!"
  |otherwise = "Not !!"
    where
      dis n = foldl (\acc (i,d)-> acc + (d^i) ) 
              0
              (zip [1..] (map (read . (:[])) (show n)))

---------------
module Disarium where

disariumNumber :: Int -> String
disariumNumber n
  | n == x = "Disarium !!"
  | otherwise = "Not !!"
  where
    indexed = zip [(0 :: Int) ..] $ show n
    x = foldl f 0 indexed
    f :: Int -> (Int, Char) -> Int
    f a b = a + read [snd b] ^ (fst b + 1)

------------------
module Disarium where

disariumNumber :: Int -> String
disariumNumber n = if disariumNumber' n then "Disarium !!" else "Not !!"

disariumNumber' :: Int -> Bool
disariumNumber' n = (n==) . sum . zipWith (flip (^)) [1..] . map (read . (:[])) $ show n

-------------

module Disarium where

disariumNumber :: Int -> String
disariumNumber n = if sumDigit == n then "Disarium !!" else "Not !!"
  where
    digits = map (\c -> read [c]) $ show n
    sumDigit = sum $ zipWith (\digit pos -> digit ^ pos) digits [1..]

----------------

module Disarium where

disariumNumber :: Int -> String
disariumNumber n = if condition then "Disarium !!" else "Not !!"
 where condition = n == sum [read([c]) ^ i | (i, c) <- zip [1..] (show n)]    
