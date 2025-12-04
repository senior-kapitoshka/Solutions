module FormatSentence where 

formatWords :: [String] -> String 
formatWords [] = ""
formatWords list = format (zip [0..] fltrList) ""
  where 
    fltrList = filter (\str-> str/="") list
    format [] newString = newString
    format (x:xs) newString
      | (fst x /= sz-2)&& (fst x /= sz-1)  = format xs (newString ++ snd x ++ ", ")
      | (fst x == sz-2) = format xs (newString ++ snd x ++ " and ")
      | otherwise = newString ++ snd x
        where
          sz= length fltrList
          

-------------------
module FormatSentence where 
formatWords :: [String] -> String 
formatWords = f . filter (/= "") where
  f [] = ""
  f [x] = x
  f [x, y] = x ++ " and " ++ y
  f (x : xs) = x ++ ", " ++ f xs

  ------------
  module FormatSentence where 

import Data.List

formatWords :: [String] -> String 
formatWords xs = case filter (not . null) xs of
  [] -> []
  [x] -> x
  xs' -> intercalate ", " (init xs') ++ " and " ++ last xs'

  ------------
            