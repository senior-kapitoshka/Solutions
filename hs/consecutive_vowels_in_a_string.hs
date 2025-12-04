module ConsecutiveVowelsinaString (getTheVowels) where

getTheVowels :: String -> Int
getTheVowels str = calc str (chars!!0) 0 0
  where
    calc [] char idx res = res
    calc (x:xs) char idx res
      | elem x chars && x==char && idx<4 = calc xs (chars!!(idx+1)) (idx+1) (res+1)
      | elem x chars && x==char && idx==4 = calc xs (chars!!0) 0 (res+1)
      | otherwise = calc xs char idx res
    
    chars = ['a', 'e', 'i', 'o', 'u']

-----------------
module ConsecutiveVowelsinaString (getTheVowels) where

getTheVowels :: String -> Int
getTheVowels xs = go (dropWhile (/= 'a') xs) (cycle "eioua")
  where
    go (x : xs) (y : ys) = (+) 1 . go (dropWhile (/= y) xs) $ ys
    go _ _ = 0

-------------
module ConsecutiveVowelsinaString (getTheVowels) where

getTheVowels :: String -> Int
getTheVowels = fst . foldl f (0, cycle "aeiou")
  where f (n, vs) c
          | c == head vs = (n + 1, tail vs)
          | otherwise    = (n, vs)


--------------
module ConsecutiveVowelsinaString (getTheVowels) where

getTheVowels :: String -> Int
getTheVowels = solve 'a' where
  vowels = zip <*> tail . cycle $ "aeiou"
  next vowel | Just vowel' <- lookup vowel vowels = vowel'
  solve vowel [] = -1
  solve vowel word = 1 + solve (next vowel) (dropWhile (/= vowel) word)

  --------------
  module ConsecutiveVowelsinaString (getTheVowels) where

getTheVowels :: String -> Int
getTheVowels = fst . foldl f (0, cycle "aeiou")
    where
        f :: (Int, String) -> Char -> (Int, String)
        f (n, v:vs) c
          | v == c = (n + 1, vs)
          | otherwise = (n, v:vs)

-----------
module ConsecutiveVowelsinaString (getTheVowels) where


getTheVowels :: String -> Int
getTheVowels =  f $ cycle "aeiou"

f l@(x:xs) (y:ys)
 | x == y = 1 + f xs ys
 | otherwise = f l ys

f _ _ = 0          