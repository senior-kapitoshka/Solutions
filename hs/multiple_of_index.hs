module MultipleOfIdx where 

multipleOfIndex :: [Int] -> [Int]
multipleOfIndex xs = [x | (i,x) <- zip [0..] xs, i /= 0, x `mod` i == 0]

--

module MultipleOfIdx where 

multipleOfIndex :: [Int] -> [Int]
multipleOfIndex (_:xs) = [x | (x,i)<-zip xs [1..], mod x i == 0] 

---
module MultipleOfIdx where 

multipleOfIndex :: [Int] -> [Int]
multipleOfIndex xs = [a | (a,b) <- zip xs [0..], b > 0, rem a b == 0]

--
module MultipleOfIdx where 

multipleOfIndex :: [Int] -> [Int]
multipleOfIndex (x:xs) = multiplyByItsIndex xs 1
  where multiplyByItsIndex :: [Int] -> Int -> [Int]
        multiplyByItsIndex [] _ = []
        multiplyByItsIndex (x:xs) i
          | x `mod` i == 0 = [x] ++ multiplyByItsIndex xs (succ i)
          | otherwise = multiplyByItsIndex xs (succ i)
        

        ---

        multiplesOfIndex xs = map snd $ filter (\(i, x) -> i /= 0 && x `mod` i == 0) $ zip [0..] xs
