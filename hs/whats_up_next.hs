module LazyNext where

next :: Eq a => a -> [a] -> Maybe a
next _ [] = Nothing
next _ [_] = Nothing
next item (x:y:xs)
  | x == item = Just y
  | otherwise = next item (y:xs)

  --

  module LazyNext where

import Data.Maybe (listToMaybe)

next :: Eq a => a -> [a] -> Maybe a
next item = listToMaybe . drop 1 . dropWhile (/=item)

---

module LazyNext where

next :: Eq a => a -> [a] -> Maybe a
next item xs = case xs of [] -> Nothing
                          [x] -> Nothing
                          (hd:tl) -> if hd==item then Just (head tl) else next item tl
--
