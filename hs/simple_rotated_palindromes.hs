module SimpleRotatedPalin where 

solve :: String -> Bool
solve [] = True
solve xs = rotate ([last xs] ++ (init xs)) (length xs)
  where
    rotate xs cnt
      | cnt == 0 = False
      | check xs = True  
      | otherwise = rotate ([last xs] ++ (init xs)) (cnt-1)
          where
            check str = str == reverse str

-------------------
module SimpleRotatedPalin where 

import Data.List (inits, tails)

solve :: String -> Bool
solve = any ((==) <*> reverse) . (zipWith (++) <$> tails <*> inits)

---------------
module SimpleRotatedPalin where 

solve :: String -> Bool
solve [] = True
solve xs = any (\s -> (reverse s) == s) [(drop n xs) ++ (take n xs) | n <- [0..length xs -1]]

--------------
module SimpleRotatedPalin where 

import Data.List

solve :: String -> Bool
solve xs = any isPalindrome $ zipWith (++) (tails xs) (inits xs) where
  isPalindrome = reverse >>= (==)

----------------
  